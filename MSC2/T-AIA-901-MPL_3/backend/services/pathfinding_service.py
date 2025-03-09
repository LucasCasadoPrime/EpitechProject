from repositories.route_repository import RouteRepository
import networkx as nx

class PathfindingService:
    def __init__(self):
        self.route_repo = RouteRepository()

    def get_datas(self):
        return self.route_repo.get_all_routes()
    
    def getDepartureAndArrivalLocations(self, data):
        locations = []
        for route in data:
            locations.append((route.Departure, route.Arrival))
        return locations

    def getDuration(self, data):
        durations = []
        for route in data:
            durations.append(route.Duration)
        return durations

    def create_graph(self):
        data = self.get_datas()
        locations = self.getDepartureAndArrivalLocations(data)
        durations = self.getDuration(data)

        if len(locations) != len(durations):
            print(f"Mismatch: {len(locations)} locations vs {len(durations)} durations")
            return
        
        G = nx.DiGraph()  # Create a directed graph
        for i in range(len(locations)):
            departure, arrival = locations[i]
            duration = durations[i]
            G.add_edge(departure, arrival, weight=duration)
        return G
    

    def find_shortest_path(self, start, end, graph):
        try:
            length, path = nx.single_source_dijkstra(graph, start, end, weight="weight")
            return {"path": path, "duration": length}
        except nx.NetworkXNoPath:
            print({"error": f"No path found from {start} to {end}"})
        except nx.NodeNotFound:
            print({"error": f"Node not found from {start} to {end}"})