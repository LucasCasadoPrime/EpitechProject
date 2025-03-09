import { Button } from "@/app/ui/button";
import CardComponent from "@/app/ui/deck/card-component";
import { fetchCardData } from "@/app/lib/data";

export default async function Page() {
  const cards = await fetchCardData();
  const numImages = 24;
  return (
    <main className="m-5">
      <div className="flex items-center space-x-4 m-2">
        <Button>Chercher</Button>
        <Button>Couleur</Button>
        <Button>Extension</Button>
        <Button>Deck</Button>
        <Button>Créer</Button>
      </div>
      <div className="flex flex-wrap justify-center items-center">
        {Array.from({ length: numImages }).map((_, index) => (
          <div key={index} className="m-1">
            <CardComponent link="https://cards.scryfall.io/small/front/b/d/bd8fa327-dd41-4737-8f19-2cf5eb1f7cdd.jpg?1614638838" />
          </div>
        ))}
      </div>
    </main>
  );
}
