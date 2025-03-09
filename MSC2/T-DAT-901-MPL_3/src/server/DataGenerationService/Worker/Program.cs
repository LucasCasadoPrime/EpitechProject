using Confluent.Kafka;
using Worker;
using Worker.CardDataGeneration;
using Worker.MagicDataProvider;

var builder = Host.CreateApplicationBuilder(args);

builder.Services.AddHttpClient<ICardProvider, CardProvider>(client =>
{
    client.BaseAddress = new Uri("https://api.scryfall.com/");
    client.DefaultRequestHeaders.Add("Accept", "*/*");
    client.DefaultRequestHeaders.Add("User-Agent", "DataGenerationService");
});

builder.Services.AddSingleton(_ =>
{
    var config = new ProducerConfig
    {
        BootstrapServers = "broker-1:19092,broker-2:19092,broker-3:19092",
        EnableIdempotence = true,
        Acks = Acks.All,
        MessageSendMaxRetries = 3
    };

    return new ProducerBuilder<Null, string>(config).Build();
});

builder.Services.AddSingleton<ICardDataGenerationService, CardDataGenerationService>()
    .AddHostedService<BackgroundWorker>();

var host = builder.Build();
host.Run();
