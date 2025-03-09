using Dto.CardPrices;
using Dto.Enums;
using Worker.CardDataGeneration;

namespace Worker.MagicDataProvider;

public interface ICardProvider
{
    Task<List<CardPrice>> GetCardsBySetAsync(SetCode setCode);
}