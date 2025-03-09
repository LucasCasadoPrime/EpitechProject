using Api.Consumers;
using Api.WebSockets;
using Confluent.Kafka;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddSingleton<IConsumer<Ignore, string>>(sp =>
{
    var config = new ConsumerConfig
    {
        BootstrapServers = "broker-1:19092,broker-2:19092,broker-1:19092",
        GroupId = "card-price-consumer-group",
        AutoOffsetReset = AutoOffsetReset.Earliest,
        EnableAutoCommit = true,
        ApiVersionRequest = false,
        SocketTimeoutMs = 6000,
        SessionTimeoutMs = 10000,
    };

    return new ConsumerBuilder<Ignore, string>(config).Build();
});

builder.Services.AddSingleton<IConsumerService, ConsumerService>();
builder.Services.AddTransient<IWebSocketService, WebSocketService>();

builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();


app.UseSwagger();
app.UseSwaggerUI();

app.UseHttpsRedirection();

app.UseAuthorization();

app.UseWebSockets();

app.MapControllers();

app.Run();