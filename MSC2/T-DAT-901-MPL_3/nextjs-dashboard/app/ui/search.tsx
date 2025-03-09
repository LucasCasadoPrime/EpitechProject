import { useState } from "react";
import { CardType } from "../lib/definitions";

export default function Search({
  placeholder,
  card,
  inputValue,
  onInputChange,
  onCardClick,
}: {
  placeholder: string;
  card: CardType[];
  inputValue: string;
  onInputChange: (value: string) => void;
  onCardClick: (name: string) => void;
}) {
  const [filteredCard, setFilteredCard] = useState<CardType[]>(card);

  const handleInputChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const value = e.target.value;
    onInputChange(value);
    setFilteredCard(
      card.filter((c) => c.name.toLowerCase().includes(value.toLowerCase()))
    );
  };

  const handleItemClick = (name: string) => {
    onInputChange(name);
    onCardClick(name); // Appelle la fonction pour transmettre la carte sélectionnée
    setFilteredCard([]);
  };

  return (
    <div className="relative flex flex-1 flex-shrink-0">
      <label htmlFor="search" className="sr-only">
        Search
      </label>
      <div className="relative w-full">
        <input
          className="peer block w-full rounded-md border border-gray-200 py-[9px] pl-10 text-sm outline-2 placeholder:text-gray-500"
          placeholder={placeholder}
          value={inputValue}
          onChange={handleInputChange}
          onClick={() => setFilteredCard(card)}
        />
        {inputValue && filteredCard.length > 0 && (
          <ul className="absolute z-10 mt-1 w-full bg-white border border-gray-200 rounded-md shadow-lg">
            {filteredCard.slice(0, 5).map((c) => (
              <li
                key={c.id}
                className="cursor-pointer px-4 py-2 hover:bg-gray-100"
                onClick={() => handleItemClick(c.name)}
              >
                {c.name}
              </li>
            ))}
          </ul>
        )}
      </div>
    </div>
  );
}
