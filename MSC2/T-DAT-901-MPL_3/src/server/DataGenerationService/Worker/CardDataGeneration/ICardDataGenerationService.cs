using Dto.CardPrices;

namespace Worker.CardDataGeneration;

public interface ICardDataGenerationService
{
    List<CardPrice> GenerateSoftCardPricesAsync(List<CardPrice> cards);
}