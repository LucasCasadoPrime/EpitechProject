using System.Net.Http.Json;
using Dto.CardPrices;
using Dto.Enums;
using Dto.Scryfall;
using Worker.CardDataGeneration;

namespace Worker.MagicDataProvider;

public class CardProvider(HttpClient httpClient) : ICardProvider
{
    public async Task<List<CardPrice>> GetCardsBySetAsync(SetCode setCode)
    {
        var response = await httpClient.GetAsync($"cards/search?order=set&q=e%3A{setCode}");
        var cards = await response.Content.ReadFromJsonAsync<CardsSearchBySet>();
        if (cards?.Data is null)
        {
            throw new Exception($"Failed to retrieve cards using set code : {setCode}.");
        }

        return cards.Data.Select(card => new CardPrice
            {
                Id = card.Id,
                Prices = card.Prices,
            }).ToList();
    }
}