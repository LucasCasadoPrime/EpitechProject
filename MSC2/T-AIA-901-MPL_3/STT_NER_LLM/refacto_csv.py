import pandas as pd

df = pd.read_csv('./data/timetables.csv', delimiter='\t')

split_trajet = df['trajet'].str.split(' - ', n=1, expand=True)
df['departure'] = split_trajet[0]
df['arrival'] = split_trajet[1]

df.drop(columns=['trip_id', 'trajet'], inplace=True)

df.to_csv('./data/timetables2.csv', index=False)