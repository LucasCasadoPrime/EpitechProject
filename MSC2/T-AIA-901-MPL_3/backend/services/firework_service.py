import json
import os
import fireworks.client
from dotenv import load_dotenv

class FireworksService:
    def __init__(self):
        load_dotenv()
        fireworks.client.api_key = os.getenv("FIREWORKS_API_KEY")

    def process(self, messages):

        preprompts = {
            "role": "system",
            "content": """
                        Je te donne un demande d'un client qui veux voyager, donne moi la [ville_de_depart], ainsi que la [ville_arrivee].La réponse doit strictement est sous la forme suivante:
                        {
                            "departure": "Paris",
                            "arrival": "Lyon"
                        }
                        """
        }
        messages = [preprompts] + [messages]

        completion = fireworks.client.ChatCompletion.create(
            model="accounts/fireworks/models/mixtral-8x22b-instruct",
            messages=messages,
            stream=False,
            n=1,
            max_tokens=4096,
            temperature=0.6,
            stop=[],
        )
        message = completion.choices[0].message.content
        message = json.loads(message)
        return message
