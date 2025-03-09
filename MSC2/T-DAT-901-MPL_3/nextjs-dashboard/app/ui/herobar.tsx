"use client";
import Search from "./search";
import { CardType } from "@/app/lib/definitions";

export default function HeroBar({
  Card,
  inputValue,
  setInputValue,
  selectOption,
  setSelectOption,
  onCardSelect,
}: {
  Card: CardType[];
  inputValue: string;
  setInputValue: (value: string) => void;
  selectOption: string;
  setSelectOption: (value: string) => void;
  onCardSelect: (name: string) => void;
}) {
  const handleInputChange = (value: string) => {
    setInputValue(value);
  };

  return (
    <div className="flex flex-col w-full gap-10 border-solid border-gray-700 items-center bg-slate-50 p-4">
      <h1 className="text-6xl font-extrabold">Magic meta intelligence</h1>
      <h3 className="text-3xl text-slate-800">
        Suivez le prix des cartes en temps réel.
      </h3>
      <h3 className="text-3xl text-slate-800">
        {inputValue ? `Résultats pour "${inputValue}"` : "Toutes les cartes"}
      </h3>
      <div className="flex justify-center w-full gap-5">
        <div className="w-1/2">
          <Search
            placeholder={"Recherche ..."}
            card={Card}
            inputValue={inputValue}
            onInputChange={handleInputChange}
            onCardClick={onCardSelect}
          />
        </div>
        <select
          className="bg-white border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block wp-2.5"
          value={selectOption}
          onChange={(e) => setSelectOption(e.target.value)}
        >
          <option value="">Select an option</option>
          <option value="dsk">Duskmourn: House of Horror</option>
        </select>
        <button className="bg-gray-800 text-white px-4 py-2 mb-4 rounded-md hover:bg-gray-700">
          Couleurs
        </button>
        <button className="bg-gray-800 text-white px-4 py-2 mb-4 rounded-md hover:bg-gray-700">
          Extension
        </button>
      </div>
    </div>
  );
}
