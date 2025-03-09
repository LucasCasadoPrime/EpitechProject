using System.Net.WebSockets;

namespace Api.WebSockets;

public interface IWebSocketService
{
    Task SendCardPricesAsync(string cardId, WebSocket webSocket, CancellationToken cancellationToken);
}