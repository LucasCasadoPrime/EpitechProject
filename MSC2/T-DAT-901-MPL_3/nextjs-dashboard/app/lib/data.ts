import { CardType, CardPrice } from "./definitions";

export async function fetchCardData(
  selectOption: string = ""
): Promise<CardType[]> {
  try {
    const response = await fetch(
      `https://api.scryfall.com/cards/search?q=e:${selectOption}&order=set&unique=prints`
    );
    if (!response.ok) {
      throw new Error("Network response was not ok");
    }
    const data = await response.json();
    const cards: CardType[] = data.data.map((card: any) => ({
      id: card.id,
      name: card.name,
      image: card.image_uris?.normal,
      set: card.set,
      rarity: card.rarity,
    }));
    return cards;
  } catch (error) {
    console.error("Fetching fake data Error:", error);
    throw new Error("Failed to fetch card data.");
  }
}
