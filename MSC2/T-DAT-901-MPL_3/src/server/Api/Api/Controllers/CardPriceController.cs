using Api.WebSockets;
using Dto.Enums;
using Microsoft.AspNetCore.Mvc;

namespace Api.Controllers;

[ApiController]
[Route("api/[controller]")]
public class CardPriceController(IWebSocketService webSocketService) : Controller
{
    [HttpGet(nameof(GetSets))]
    public ActionResult<List<string>> GetSets()
    {
        return new List<string>
        {
            SetCode.Dsk.ToString(),
            SetCode.Lci.ToString(),
            SetCode.One.ToString()
        };
    }

    [HttpGet("GetPrice/{cardId}")]
    public async Task ConnectWebSocket(string cardId, CancellationToken cancellationToken)
    {
        if (!HttpContext.WebSockets.IsWebSocketRequest)
        {
            HttpContext.Response.StatusCode = 400;
            return;
        }

        var webSocket = await HttpContext.WebSockets.AcceptWebSocketAsync();
        
        await webSocketService.SendCardPricesAsync(cardId, webSocket, cancellationToken);
    }
}