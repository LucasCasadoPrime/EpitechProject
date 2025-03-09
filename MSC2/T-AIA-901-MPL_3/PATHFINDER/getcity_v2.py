import csv
from geopy.geocoders import Photon
from geopy.exc import GeopyError

# Read the data from the CSV file
def read_data(filename):
    data = []
    with open(filename) as csvfile:
        csvreader = csv.reader(csvfile)
        for row in csvreader:
            data.append(row)
    return data

def modify_csv(input_filename, output_filename, departureCity, arrivalCity):
    with open(input_filename, 'r') as file:
        reader = csv.reader(file)
        with open(output_filename, 'w', newline='') as file:
            writer = csv.writer(file)
            # Write header with additional columns
            header = next(reader)
            header.extend(['Departure City', 'Arrival City'])
            writer.writerow(header)
            
            # Write data with new city columns
            for row in reader:
                dep_city = next((city[0] for city in departureCity if row[1] == city[1]), 'Unknown')
                arr_city = next((city[0] for city in arrivalCity if row[2] == city[1]), 'Unknown')
                row.extend([dep_city, arr_city])
                writer.writerow(row)

def getCityStation(data, column_index, geolocator):
    cityStation = []
    for row in data:
        station = row[column_index]
        try:
            location = geolocator.geocode(station)
            if location:
                city = location.raw['properties'].get('city', 'Unknown')
                cityStation.append((city, station))
            else:
                cityStation.append(('Unknown', station))
        except GeopyError as e:
            print(f"Error retrieving data for station {station}: {e}")
            cityStation.append(('Unknown', station))
    return cityStation

def main():
    geolocator = Photon(user_agent="geoapiExercise")
    data = read_data('timetables.csv')
    
    cityDepartureStation = getCityStation(data, 1, geolocator)
    cityArrivalStation = getCityStation(data, 2, geolocator)
    
    modify_csv('timetables.csv', 'timetables_modified.csv', cityDepartureStation, cityArrivalStation)
    

if __name__ == '__main__':
    main()
