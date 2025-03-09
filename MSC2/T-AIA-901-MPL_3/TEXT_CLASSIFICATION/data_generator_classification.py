import random
import pandas as pd


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

# Example questions for the dataset
data = {
    'question': [
        "Je veux aller à {end} depuis {start}",
        "J'aime les bananes",
        "Réservez un vol pour {end}",
        "Il mange une pomme",
        "Pouvez-vous réserver une chambre d'hôtel à {end}?",
        "Le temps est ensoleillé aujourd'hui",
        "Je voudrais voyager de {start} à {end}",
        "Elle est enseignante",
        "Obtenez-moi un billet pour {end}",
        "J'aime peindre des paysages",
        "Où est la gare la plus proche?",
        "J'ai besoin d'un taxi pour l'aéroport",
        "Elle aime lire des livres",
        "Pouvez-vous m'aider à trouver un restaurant?",
        "Le musée est fermé aujourd'hui",
        "Il joue au football",
        "Veuillez réserver un hôtel à {end}",
        "Le concert commence à 20h",
        "J'apprends à jouer de la guitare",
        "J'ai besoin d'un vol de {start} à {end}.",
        "Elle aime faire de la randonnée en montagne.",
        "Pouvez-vous trouver un hôtel à {end} pour la semaine prochaine?",
        "J'ai besoin d'acheter des provisions pour la semaine.",
        "Réservez un billet de train de {start} à {end}.",
        "J'aime regarder des films le vendredi soir.",
        "Quels sont les meilleurs endroits à visiter à {end}?",
        "Le chat dort sur le canapé.",
        "Y a-t-il un service de bus de {start} à {end}?",
        "Je vais au centre commercial pour acheter de nouveaux vêtements.",
        "Pouvez-vous m'aider avec un vol de {start} à {end}?",
        "Je prévois de visiter le musée du Louvre lors de mon voyage à {end}.",
        "J'aime lire des romans pendant mon temps libre.",
        "Quel est le moyen le plus rapide pour aller de {start} à {end}?",
        "Elle aime faire de la randonnée en montagne pendant les week-ends.",
        "Je dois trouver un hébergement près de la tour Eiffel.",
        "Mon passe-temps préféré est de peindre des paysages.",
        "Comment puis-je aller de l'aéroport JFK au centre-ville de Manhattan?",
        "Je dois faire réparer ma voiture.",
        "Quel est le moyen le plus rapide pour aller de {start} à {end}?",
        "J'aime lire des romans pendant mon temps libre."
    ],
    'label': [
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 0, 0, 1, 0, 1, 0
    ]
}

# Generate a list of new questions
def generate_questions(num_questions=2000):
    questions = []
    for _ in range(num_questions):
        start = random.choice(stations)
        end = random.choice(stations)
        if start != end:  # Ensure start and end are not the same
            template = random.choice(data["question"])
            if "{start}" in template or "{end}" in template:
                question = template.format(start=start, end=end)
                label = 1
            else:
                question = template
                label = 0   
            questions.append((question, label))     
    return(questions)

# Generate new questions
new_questions = generate_questions(20000)

# Read the questions into a DataFrame
df = pd.DataFrame(new_questions, columns=['question','label'])

df.to_csv('travel_sentences.csv', index=False)

