using Confluent.Kafka;

namespace Api.Consumers;

public class ConsumerService : IConsumerService, IDisposable
{
    private readonly IConsumer<Ignore, string> _consumer;

    public ConsumerService(IConsumer<Ignore, string> consumer)
    {
        _consumer = consumer;

        _consumer.Subscribe("card-price");
    }

    public string? Execute(CancellationToken cancellationToken)
    {
        try
        {
            var result = _consumer.Consume(cancellationToken);
            
            return result?.Message?.Value;
        }
        catch (Exception)
        {
            return null;
        }
    }

    public void Dispose()
    {
        _consumer.Close();
        _consumer.Dispose();
    }
}