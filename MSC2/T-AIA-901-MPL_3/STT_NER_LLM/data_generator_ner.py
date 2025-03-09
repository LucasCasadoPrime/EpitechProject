import random
import pandas as pd

# Sample of French train stations and cities to use in generating questions
stations = [
    "Lyon", "Paris", "Marseille", "Bordeaux", "Nantes", "Toulouse", 
    "Strasbourg", "Lille", "Nice", "Montpellier", "Rennes", "Grenoble",
    "Tours", "Le Mans", "Dijon", "Brest", "Rouen", "Caen", "Amiens", 
    "Nancy", "Metz", "Orléans", "Limoges", "Reims", "Angers",
    "Clermont-Ferrand", "Saint-Étienne", "Toulon", "Le Havre", "Avignon",
    "Perpignan", "Besançon", "Mulhouse", "Roubaix", "Tourcoing", "Nîmes",
    "Villeurbanne", "Saint-Denis", "Argenteuil", "Montreuil", "Rouen",
    "Boulogne-Billancourt", "Nancy", "Saint-Denis", "Roubaix", "Tourcoing",
    "Nanterre", "Vitry-sur-Seine", "Créteil", "Dunkerque", "Aubervilliers",
    "Bezier", "Bourges", "Carcassonne", "Chambéry", "Colmar", "La Rochelle",
    "La Seyne-sur-Mer", "Le Tampon", "Pau", "Saint-Maur-des-Fossés",
    "Saint-Nazaire", "Sarcelles", "Tarbes", "Vénissieux", "Ajaccio",
    "Albi", "Angoulême", "Annecy", "Arras", "Aulnay-sous-Bois", "Bastia",
    "Bayonne", "Beauvais", "Belfort", "Bobigny", "Bondy", "Brive-la-Gaillarde",
    "Cagnes-sur-Mer", "Calais", "Cannes", "Castres", "Chalon-sur-Saône",
    "Charleville-Mézières", "Cholet", "Clamart", "Clichy", "Cognac",
    "Colombes", "Compiègne", "Creil", "Douai", "Draguignan", "Drancy",
    "Échirolles", "Épinal", "Évreux", "Fontenay-sous-Bois", "Fréjus",
    "Garges-lès-Gonesse", "Gennevilliers", "Gonesse", "Grasse", "Haguenau",
    "Issy-les-Moulineaux", "Joué-lès-Tours", "La Ciotat", "Le Cannet",
    "Le Perreux-sur-Marne", "Lens", "Liévin", "Lorient", "Maubeuge",
    "Meaux", "Melun", "Montauban", "Montluçon", "Montélimar", "Montigny-le-Bretonneux",
    "Nevers", "Noisy-le-Grand", "Pant", "Pessac", "Poissy", "Pontault-Combault",
    "Pontoise", "Quimper", "Rambouillet", "Roanne", "Romans-sur-Isère",
    "Saint-Brieuc", "Saint-Chamond", "Saint-Germain-en-Laye", "Saint-Laurent-du-Var",
]

# Templates for generating new questions
templates = [
    "Je veux aller de {start} à {end}",
    "Comment puis-je me rendre à {end} depuis {start} ?",
    "Y a-t-il des trains entre {start} et {end} ?",
    "Je souhaite me rendre à {end} en partant de {start}.",
    "Quels sont les horaires des trains de {start} à {end} ?",
    "Est-ce qu'il y a un train direct entre {start} et {end} ?",
    "Je dois aller à {end} depuis {start}, comment faire ?",
    "Puis-je prendre un train de {start} à {end} ?",
    "Quels trains vont de {start} à {end} ?",
    "Je veux voyager de {start} à {end}.",
    "Quel est le meilleur itinéraire de {start} à {end} ?",
    "Combien de temps faut-il pour aller de {start} à {end} ?",
    "Quels sont les arrêts entre {start} et {end} ?",
    "Y a-t-il des réductions pour les billets de {start} à {end} ?",
    "Quels sont les prix des billets de {start} à {end} ?",
    "Quels sont les trains les plus rapides de {start} à {end} ?",
    "Quels sont les trains les moins chers de {start} à {end} ?",
    "Y a-t-il des trains de nuit entre {start} et {end} ?",
    "Quels sont les services disponibles à bord des trains de {start} à {end} ?",
    "Puis-je réserver un billet de {start} à {end} en ligne ?",
    "Quels sont les horaires des premiers et derniers trains de {start} à {end} ?",
    "Y a-t-il des correspondances entre {start} et {end} ?",
    "Quels sont les trains directs de {start} à {end} ?",
    "Quels sont les trains avec correspondance de {start} à {end} ?",
    "Je veux aller de {start} vers {end}.",
    "Quels sont les trains qui partent de {start} à destination de {end} ?",    
    "Je veux voyager de {start} vers {end}.",
    "Je veux prendre un train de {start} à {end}.",
    "Je veux prendre un train de {start} vers {end}.",
    "Je voudrai aller a {end}.",
    "Je voudrai partir de {start} pour aller a {end}.",
    "Je voudrai partir de {start}.",
    "Je voudrai prendre un train en direction de {end}.",
    "Je voudrai prendre un train en direction de {end} depuis {start}.",

]

# Generate a list of new questions
def generate_questions(num_questions=2000):
    questions = []
    for _ in range(num_questions):
        start = random.choice(stations)
        end = random.choice(stations)
        if start != end:  # Ensure start and end are not the same
            template = random.choice(templates)
            question = template.format(start=start, end=end)
            questions.append((question, start, end))
    return questions

# Generate new questions
new_questions = generate_questions(100000)

# Read the questions into a DataFrame
df = pd.DataFrame(new_questions, columns=['question', 'start', 'end'])

# Function to convert questions to NER format
def convert_to_ner_format(row):
    tokens = row['question'].split()
    ner_format = []
    start_tokens = row['start'].split()
    end_tokens = row['end'].split()
    
    i = 0
    while i < len(tokens):
        token = tokens[i]
        if token in start_tokens:
            for j, start_token in enumerate(start_tokens):
                label = 'B-START' if j == 0 else 'I-START'
                ner_format.append((start_token, label))
                i += 1
        elif token in end_tokens:
            for j, end_token in enumerate(end_tokens):
                label = 'B-END' if j == 0 else 'I-END'
                ner_format.append((end_token, label))
                i += 1
        else:
            ner_format.append((token, 'O'))
            i += 1
    
    return ner_format

# Apply the conversion to the entire dataframe
ner_data = df.apply(convert_to_ner_format, axis=1)

# Flatten the list of tuples and create a new DataFrame
flattened_ner_data = [item for sublist in ner_data for item in sublist]
ner_df = pd.DataFrame(flattened_ner_data, columns=['token', 'label'])

# Add sentence_id column
ner_df['sentence_id'] = (ner_df['token'] == '?').cumsum()

# Define the label mapping
label_mapping = {"O": 0, "B-START": 1, "I-START": 2, "B-END": 3, "I-END": 4}

# Add ner_tag column with numerical labels
ner_df['ner_tag'] = ner_df['label'].map(label_mapping)

# Save the NER formatted data to a CSV file
ner_df.to_csv('ner_training_data2.csv', index=False)

# Display the first 10 rows of the NER formatted data
print(ner_df.head(10))