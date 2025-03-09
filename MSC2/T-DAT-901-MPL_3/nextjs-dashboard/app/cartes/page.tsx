"use client";

import PriceDataChart from "@/app/ui/dashboard/pricedata-chart";
import { fetchCardData } from "@/app/lib/data";
import HeroBar from "../ui/herobar";
import { Card } from "../ui/dashboard/cards";
import ImageComponent from "../ui/deck/card-component";
import { useState, useEffect } from "react";
import { CardPrice, CardType } from "../lib/definitions";

export default function Page() {
  const [prices, setPrices] = useState<CardPrice[]>([]);
  const [card, setCard] = useState<CardType[]>([]);
  const [inputValue, setInputValue] = useState("");
  const [loading, setLoading] = useState(true);
  const [selectOption, setSelectOption] = useState("");
  const [selectCard, setSelectCard] = useState<CardType | null>(null);

  useEffect(() => {
    if (!selectCard?.id) return;

    const socket = new WebSocket(
      `ws://127.0.0.1:8080/api/CardPrice/GetPrice/${selectCard.id}`
    );

    socket.onopen = () => {
      console.log("WebSocket connection established");
    };

    socket.onmessage = (event) => {
      try {
        const message = JSON.parse(event.data);

        const items = Array.isArray(message) ? message : [message];

        items.forEach((item: any) => {
          if (item.Id === selectCard.id) {
            const formattedData: CardPrice = {
              id: item.Id,
              date: new Date(item.Date),
              price: parseFloat(item.Prices?.Eur ?? "0"),
            };

            setPrices((prevPrices) => {
              const updatedPrices = [...prevPrices, formattedData];
              const limitedPrices = updatedPrices.slice(-8); // Garde les 8 derniers
              return limitedPrices;
            });
          }
        });
      } catch (err) {
        console.error("Erreur lors de la réception du message :", err);
      }
    };

    socket.onerror = (error) => {
      console.error("WebSocket error:", error);
    };

    socket.onclose = () => {
      console.log("WebSocket connection closed");
    };

    return () => {
      socket.close();
    };
  }, [selectCard]);

  useEffect(() => {
    const loadData = async () => {
      setLoading(true);
      try {
        const fetchedCards = await fetchCardData(selectOption);
        setCard(fetchedCards);
      } catch (error) {
        console.error("Erreur de chargement des données :", error);
      } finally {
        setLoading(false);
      }
    };
    loadData();
  }, [selectOption]);

  const handleCardSelect = (cardName: string) => {
    const selected = card.find((c) => c.name === cardName);
    if (selected) {
      setSelectCard(selected);
      setPrices([]);
    }
  };

  if (loading) {
    return <div>Chargement des données...</div>;
  }

  return (
    <main>
      <HeroBar
        Card={card}
        inputValue={inputValue}
        setInputValue={setInputValue}
        selectOption={selectOption}
        setSelectOption={setSelectOption}
        onCardSelect={handleCardSelect}
      />
      <div className="flex flex-row items-center justify-between">
        <PriceDataChart CardPrice={prices} />
        <div className="flex flex-col gap-4">
          <p>Authorisation en tournois</p>
          <Card title="Vintage" type="vintage" />
          <Card title="Legacy" type="legacy" />
          <Card title="Pioneer" type="pioneer" />
          <Card title="Modern" type="modern" />
        </div>
        <ImageComponent link={selectCard?.image ?? ""} />
      </div>
    </main>
  );
}
