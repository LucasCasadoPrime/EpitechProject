from services.class_service import CLASSService
from repositories.route_repository import RouteRepository
from services.firework_service import FireworksService
from services.ner_service import NERService
from services.pathfinding_service import PathfindingService

from model.route import Route
import unidecode


class ProcessManager:
    def __init__(self):
        self.route_repo = RouteRepository()
        self.pathfinder_service = PathfindingService()
        self.ner_service = NERService("Crysy-rthomas/T-AIA-CamemBERT-NER-V2")
        self.class_service = CLASSService(
            "InesPL84/T-AIA-DISTILCAMEMBERT-BASE-TEXT-CLASSIFICATION"
        )
        self.fireworks_service = FireworksService()
        self.data = {}

    def add_data(self, csv_file):
        csv = csv_file.file.read().decode("utf-8")
        # remove first line
        csv = csv[csv.find("\n") + 1 :]
        for line in csv.split("\n"):
            if line:
                trip_id, Departure, Arrival, Duration, Departure_City, Arrival_City = (
                    line.split(",")
                )
                route = Route(
                    trip_id=trip_id,
                    Departure=Departure,
                    Arrival=Arrival,
                    Duration=Duration,
                    Departure_City=Departure_City,
                    Arrival_City=Arrival_City,
                )
                self.route_repo.create_route(route)

    def process(self, query, service):

        # Check if query is valid
        chck = self.class_service.predict_class(query)
        if chck == "NEGATIVE":
            return "error : query is not valid ! here some exemple : 'je veux aller de Paris à Lyon' or 'Voyager vers Paris depuis Lyon' or 'faire un trajet Paris - Lyon"

        formated_query = {"role": "user", "content": query}
        if service == "ner":
            self.data["ner"] = self.ner_service.predict_ner(query)
        elif service == "llm":
            self.data["llm"] = self.fireworks_service.process(formated_query)
        else:
            self.data["ner"] = self.ner_service.predict_ner(query)
            self.data["llm"] = self.fireworks_service.process(formated_query)

        start, end = self.retrieve_start_end(service)

        start = [unidecode.unidecode(city) for city in start]
        end = [unidecode.unidecode(city) for city in end]
        #remove extra spaces
        start = [city.replace(" ","") for city in start]
        end = [city.replace(" ","") for city in end]

        starting_trainstations = []
        ending_trainstations = []
        for start_city in start:
            starting_trainstations.extend(
                [station[0] for station in self.route_repo.get_all_starts(start_city)]
            )
        for end_city in end:
            ending_trainstations.extend(
                [station[0] for station in self.route_repo.get_all_ends(end_city)]
            )

        paths = []
        graph = self.pathfinder_service.create_graph()
        for trainstation_start in starting_trainstations:
            for trainstation_end in ending_trainstations:
                pth = self.pathfinder_service.find_shortest_path(
                    trainstation_start, trainstation_end, graph
                )
                if pth:
                    paths.append(pth)

        # order by duration
        paths.sort(key=lambda x: x["duration"])
        return paths

    def retrieve_start_end(self, service):
        start = []
        end = []
        if service == "ner":
            start.append(self.data["ner"]["departure"])
            end.append(self.data["ner"]["arrival"])
        elif service == "llm":
            start.append(self.data["llm"]["departure"])
            end.append(self.data["llm"]["arrival"])
        else:
            start.append(self.data["ner"]["departure"])
            end.append(self.data["ner"]["arrival"])
            start.append(self.data["llm"]["departure"])
            end.append(self.data["llm"]["arrival"])

        return start, end
