namespace Dto.Scryfall;

public class CardsSearchBySet
{
    public string? Object { get; set; }
    public int TotalCards { get; set; }
    public bool HasMore { get; set; }
    public string? NextPage { get; set; }
    public List<CardSearchBySet>? Data { get; set; }
}