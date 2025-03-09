using Dto.Enums;
using Dto.Scryfall;

namespace Dto.CardPrices;

public class CardPrice
{
    public string? Id { get; set; }
    public DateTime Date { get; set; }
    public SetCode Set { get; set; } 
    public PricesSearchBySet? Prices { get; set; }
}