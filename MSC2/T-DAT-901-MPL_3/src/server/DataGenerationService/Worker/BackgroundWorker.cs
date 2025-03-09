using System.Text.Json;
using Confluent.Kafka;
using Dto.CardPrices;
using Dto.Enums;
using Worker.CardDataGeneration;
using Worker.MagicDataProvider;

namespace Worker;

public class BackgroundWorker(
    ICardProvider cardProvider,
    ICardDataGenerationService cardDataGenerationService,
    IProducer<Null, string> producer) : BackgroundService
{
    private const string TopicName = "card-price";
    private readonly List<SetCode> _sets = [
        SetCode.Dsk,
        SetCode.Lci,
        SetCode.One
    ];
    
    protected override async Task ExecuteAsync(CancellationToken cancellationToken)
    {
        var cardsSets = new[]
        {
            await cardProvider.GetCardsBySetAsync(_sets[0]),
            await cardProvider.GetCardsBySetAsync(_sets[1]),
            await cardProvider.GetCardsBySetAsync(_sets[2])
        };
        
        while(!cancellationToken.IsCancellationRequested)
        {
            await Task.Delay(1000, cancellationToken);

            var generatePricesCardsSets = GeneratePrices(cardsSets);
            foreach (var generatePricesCardsSet in generatePricesCardsSets)
            {
                var topic = generatePricesCardsSet.First().Set;
                try
                {
                    await producer.ProduceAsync(
                        SetTopicPartition(topic),
                        SetMessage(generatePricesCardsSet), 
                        cancellationToken);
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Erreur lors de l'envoi : {ex.Message}");
                }
            }
        }
    }

    private IEnumerable<List<CardPrice>> GeneratePrices(List<CardPrice>[] cardPricesSets)
    {
        return cardPricesSets.Select(cardDataGenerationService.GenerateSoftCardPricesAsync);
    }

    private static Message<Null, string> SetMessage(List<CardPrice> cardPrices)
    {
        var messageValue = JsonSerializer.Serialize(cardPrices);
        
        return new Message<Null, string> { Value = messageValue }; 
    }

    private static TopicPartition SetTopicPartition(SetCode setCode)
    {
        var currentSet = (int)setCode;
        
        return new TopicPartition(TopicName, new Partition(currentSet));
    }
}
