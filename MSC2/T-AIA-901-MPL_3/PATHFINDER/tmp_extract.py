import csv
from collections import defaultdict

def parse_csv(file_path):
    stations = []
    with open(file_path, mode='r', encoding='utf-8') as file:
        reader = csv.DictReader(file, delimiter=';')
        for row in reader:
            stations.append(row)
    return stations

def filter_stations_by_code_ligne(stations):
    code_ligne_dict = defaultdict(list)
    for station in stations:
        code_ligne_dict[station['CODE_LIGNE']].append(station)
    return code_ligne_dict

def parse_pk(pk):
    try:
        return float(pk.replace('+', '.').replace('-', '.'))
    except ValueError:
        return float('inf')

def sort_stations_by_pk(stations):
    return sorted(stations, key=lambda x: parse_pk(x['PK']))

def create_travel_itinerary(stations):
    itinerary = []
    for station in stations:
        itinerary.append({
            'Station': station['LIBELLE'],
            'Commune': station['COMMUNE'],
            'Departement': station['DEPARTEMEN'],
            'Coordinates': station['Geo Point']
        })
    return itinerary

def main():
    file_path = 'liste-des-gares.csv'
    stations = parse_csv(file_path)
    code_ligne_dict = filter_stations_by_code_ligne(stations)
    
    for code_ligne, stations in code_ligne_dict.items():
        sorted_stations = sort_stations_by_pk(stations)
        travel_itinerary = create_travel_itinerary(sorted_stations)
        
        print(f"Travel itinerary for CODE_LIGNE {code_ligne}:")
        for stop in travel_itinerary:
            print(f"Station: {stop['Station']}, Commune: {stop['Commune']}, Departement: {stop['Departement']}, Coordinates: {stop['Coordinates']}")
        print("\n")

if __name__ == "__main__":
    main()