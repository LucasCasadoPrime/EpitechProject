namespace Api.Consumers;

public interface IConsumerService
{
    string? Execute(CancellationToken cancellationToken);
}