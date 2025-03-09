import csv
import random
import uuid
from collections import defaultdict

def parse_csv(file_path):
    stations = []
    with open(file_path, mode='r', encoding='utf-8') as file:
        reader = csv.DictReader(file, delimiter=';')
        for row in reader:
            if row['VOYAGEURS'] == 'O':
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

def estimate_duration(start_pk, end_pk):
    # Example logic: 1 minute per kilometer
    try:
        start = parse_pk(start_pk)
        end = parse_pk(end_pk)
        return int(abs(end - start) * (1/3))  # 1 minute per kilometer
    except ValueError:
        return random.randint(10, 120)  # Random duration between 10 and 120 minutes

def merge_travel_pairs(travel_pairs, threshold=10):
    merged_pairs = []
    i = 0
    while i < len(travel_pairs):
        current_pair = travel_pairs[i]
        j = i + 1
        while j < len(travel_pairs) and travel_pairs[j]['Duration'] < threshold:
            current_pair['Arrival'] = travel_pairs[j]['Arrival']
            current_pair['Arrival_City'] = travel_pairs[j]['Arrival_City']
            current_pair['Duration'] += travel_pairs[j]['Duration']
            j += 1
        merged_pairs.append(current_pair)
        i = j
    return merged_pairs

def create_travel_pairs(stations):
    travel_pairs = []
    for i in range(len(stations)):
        for j in range(i + 1, len(stations)):
            duration = estimate_duration(stations[i]['PK'], stations[j]['PK'])
            if duration >= 10:
                travel_pairs.append({
                    'ID': str(uuid.uuid4()),
                    'Departure': stations[i]['LIBELLE'],
                    'Arrival': stations[j]['LIBELLE'],
                    'Duration': duration,
                    'Departure_City': stations[i]['COMMUNE'],
                    'Arrival_City': stations[j]['COMMUNE']
                })
    travel_pairs = merge_travel_pairs(travel_pairs)
    return travel_pairs

def save_travel_pairs_to_csv(travel_pairs, output_file):
    keys = travel_pairs[0].keys()
    with open(output_file, mode='w', encoding='utf-8', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=keys)
        writer.writeheader()
        writer.writerows(travel_pairs)

def main():
    file_path = 'liste-des-gares.csv'
    output_file_template = 'travel_paris_compacted.csv'
    stations = parse_csv(file_path)
    code_ligne_dict = filter_stations_by_code_ligne(stations)
    
    all_travel_pairs = []
    for code_ligne, stations in code_ligne_dict.items():
        travel_pairs = create_travel_pairs(stations)
        all_travel_pairs.extend(travel_pairs)
    
    save_travel_pairs_to_csv(all_travel_pairs, output_file_template.format(1))
    print(f"Travel pairs dataset part")

if __name__ == "__main__":
    main()