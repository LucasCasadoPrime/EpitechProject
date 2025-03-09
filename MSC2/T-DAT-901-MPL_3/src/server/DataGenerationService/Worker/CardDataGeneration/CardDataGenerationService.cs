using System.Globalization;
using Dto.CardPrices;
using Dto.Scryfall;

namespace Worker.CardDataGeneration;

public class CardDataGenerationService : ICardDataGenerationService
{
    private readonly Random _random = new();
    
    private int Min { get; set; } = 15;
    private int Max { get; set; } = 20;
    
    public List<CardPrice> GenerateSoftCardPricesAsync(List<CardPrice> cards)
    {
        foreach (var card in cards)
        {
            card.Date = DateTime.Now;
            CheckCardPricesNullOrEmptiness(card);
            
            card.Prices!.Eur = GenerateRandomPrices(card.Prices.Eur!)
                .ToString(CultureInfo.CurrentCulture);
            
            card.Prices.Usd = GenerateRandomPrices(card.Prices.Usd!)
                .ToString(CultureInfo.CurrentCulture);
        }

        return cards;
    }

    private static void CheckCardPricesNullOrEmptiness(CardPrice card)
    {
        if (card.Prices is null 
            || string.IsNullOrEmpty(card.Prices.Eur)
            || string.IsNullOrEmpty(card.Prices.Usd))
        {
            card.Prices = new PricesSearchBySet
            {
                Eur = "0.0",
                Usd = "0.0"
            };
        }
    }

    private double GenerateRandomPrices(string price)
    {
        if (!double.TryParse(price, out var priceValue))
        {
            return 0.0;
        }

        if (priceValue <= 0.05)
        {
            Min = 60;
            Max = 75;
        }
        
        var percentage =  GenerateRandomPercentage(Min, Max);
        var increase = IncreaseOrDecrease() || priceValue <= 1;
        if (increase)
        {
            priceValue += priceValue * percentage;
        }
        else
        {
            priceValue -= priceValue * percentage;
        }

        return Math.Round(priceValue, 2);
    }
    
    private float GenerateRandomPercentage(int min, int max)
    {
        return _random.Next(min, max) / 100.0f;
    }
    
    private bool IncreaseOrDecrease()
    {
        return _random.Next(0, 2) == 0;
    }
}