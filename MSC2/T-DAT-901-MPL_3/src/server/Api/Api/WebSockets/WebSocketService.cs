using System.Net.WebSockets;
using System.Text;
using System.Text.Json;
using Api.Consumers;
using Dto.CardPrices;

namespace Api.WebSockets;

public class WebSocketService(IConsumerService consumerService) : IWebSocketService
{
    public async Task SendCardPricesAsync(string cardId, WebSocket webSocket, CancellationToken cancellationToken)
    {
        while (!cancellationToken.IsCancellationRequested)
        {
            var cards = consumerService.Execute(cancellationToken);
            if (cards == null)
            {
                return;
            }
            
            var cardPrices = JsonToCardPrices(cards);
            var cardPrice = GetCardById(cardId, cardPrices);
            var json = CardPriceToJson(cardPrice);
            var buffer = Encoding.UTF8.GetBytes(json);
            var segment = new ArraySegment<byte>(buffer);

            if (cardPrice is not null)
            {
                await webSocket.SendAsync(segment, WebSocketMessageType.Text, true, cancellationToken);
            }
        }

        await webSocket.CloseAsync(WebSocketCloseStatus.NormalClosure,
            "Fin de la communication",
            cancellationToken);
    }

    private static string CardPriceToJson(CardPrice? cardPrice)
    {
        return JsonSerializer.Serialize(cardPrice);
    }

    private static CardPrice? GetCardById(string cardId, List<CardPrice>? cardPrices)
    {
        return cardPrices?.FirstOrDefault(x => x.Id == cardId);
    }

    private static List<CardPrice> JsonToCardPrices(string json)
    {
        return JsonSerializer.Deserialize<List<CardPrice>>(json) ?? [];
    }
}