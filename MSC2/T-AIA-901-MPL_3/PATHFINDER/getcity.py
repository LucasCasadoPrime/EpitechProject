import numpy as np
import csv
from geopy.geocoders import Photon

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
            for row in reader:
                # find the city of the departure station
                for city in departureCity:
                    if row[1] == city[1]:
                        row[1] = city[0]
                # find the city of the arrival station
                for city in arrivalCity:
                    if row[2] == city[1]:
                        row[2] = city[0]
                writer.writerow(row)

def getCityDepartureStation(data):
    cityDeparture= []
    for row in data:
        departure = row[1]
        # find the city of the departure station
        geolocator = Photon(user_agent="geoapiExercisfzces")
        location = geolocator.geocode(departure)
        city = location.raw['properties'].get('city')
        cityDeparture.append((city, departure))
    return cityDeparture

def getCityArrivalStation(data):
    cityArrival= []
    for row in data:
        arrival = row[2]
        # find the city of the arrival station
        geolocator = Photon(user_agent="geoapiExercisevefs")
        location = geolocator.geocode(arrival)
        city = location.raw['properties'].get('city')
        cityArrival.append((city, arrival))
    return cityArrival



def main():
    data = read_data('timetables.csv')
    cityDepartureStation = getCityDepartureStation(data)
    cityArrivalStation = getCityArrivalStation(data)
    modify_csv('timetables.csv', 'timetables_modified.csv', cityDepartureStation, cityArrivalStation)
    


if __name__ == '__main__':
    main()