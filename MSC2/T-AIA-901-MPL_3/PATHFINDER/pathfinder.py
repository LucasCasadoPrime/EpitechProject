import csv
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

# Read the data from the CSV file
def read_data(filename):
    data = []
    with open(filename) as csvfile:
        csvreader = csv.reader(csvfile)
        for row in csvreader:
            data.append(row)
    return data

# Extract departure and arrival locations
def getDepartureAndArrivalLocations(data):
    locations = []
    for row in data:
        # Ensure the row has enough data to avoid IndexError
        parts = row[0].split('\t')[1].split(' - ')
        if len(parts) > 1:
            departure = parts[0].strip()
            arrival = parts[1].strip()
            locations.append((departure, arrival))
    return locations

# Extract durations
def getDuration(data):
    durations = []
    for row in data[1:]:
        # Ensure the row has enough data to avoid IndexError
        parts = row[0].split('\t')
        if len(parts) > 2:
            duration = parts[2].strip()
            durations.append(int(duration))
    return durations

# Create and visualize the graph
def create_and_plot_graph(locations, durations):
    if len(locations) != len(durations):
        print(f"Mismatch: {len(locations)} locations vs {len(durations)} durations")
        return

    G = nx.DiGraph()  # Create a directed graph

    # Add edges with duration as weight
    for i in range(len(locations)):
        departure, arrival = locations[i]
        duration = durations[i]
        G.add_edge(departure, arrival, weight=duration)

    # Choose a layout
    plt.figure(figsize=(20, 15))  # Larger figure size
    pos = nx.spring_layout(G, k=0.3, iterations=100)  # Adjust layout parameters

    # Draw the graph with enhanced aesthetics
    nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=500, 
            font_size=5, font_weight='bold', edge_color='gray', width=1.0, 
            arrowstyle='-|>', arrowsize=15)

    # Draw edge labels
    edge_labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10, font_color='red')

    # Display the graph
    plt.title('Train Timetable Graph')
    plt.axis('off')  # Turn off the axis
    plt.show()
    return G

def compute_shortest_path(G, start, end):
    try:
        length, path = nx.single_source_dijkstra(G, start, target=end)
        print(f"Shortest path from '{start}' to '{end}': {path}")
        print(f"Duration of the shortest path: {length:.2f} units")
    except nx.NetworkXNoPath:
        print(f"No path found between '{start}' and '{end}'")
    except nx.NodeNotFound:
        print(f"One or both nodes '{start}' or '{end}' are not in the graph")


def main():
    data = read_data('./timetables.csv')
    locations = getDepartureAndArrivalLocations(data)
    durations = getDuration(data)

    # Create and plot the graph
    G = create_and_plot_graph(locations, durations)

    # Compute the shortest path
    start = 'Gare de Lyon-Part-Dieu'
    end = 'Gare de Marseille-St-Charles'

    compute_shortest_path(G, start, end)



if __name__ == '__main__':
    main()
