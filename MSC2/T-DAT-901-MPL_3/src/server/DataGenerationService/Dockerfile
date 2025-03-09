# Étape 1 : Build
FROM mcr.microsoft.com/dotnet/sdk:8.0 AS build
WORKDIR /app

# Copier les fichiers projet pour restaurer les dépendances
COPY DataGenerationService/Worker/*.csproj ./DataGenerationService/Worker/
COPY Shared/Dto/*.csproj ./Shared/Dto/
RUN dotnet restore DataGenerationService/Worker/Worker.csproj

# Copier tout le code source
COPY DataGenerationService/Worker/ ./DataGenerationService/Worker/
COPY Shared/Dto/ ./Shared/Dto/

# Publier le projet
WORKDIR /app/DataGenerationService/Worker
RUN dotnet publish -c Release -o /app/out

# Étape 2 : Runtime
FROM mcr.microsoft.com/dotnet/aspnet:8.0
WORKDIR /app
COPY --from=build /app/out .

ENTRYPOINT ["dotnet", "Worker.dll"]
