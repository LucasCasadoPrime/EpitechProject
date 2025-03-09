# Étape 1 : Build
FROM mcr.microsoft.com/dotnet/sdk:8.0 AS build
WORKDIR /app
EXPOSE 8080

# Copier les fichiers projet pour restaurer les dépendances
COPY Api/Api/*.csproj ./Api/Api/
COPY Shared/Dto/*.csproj ./Shared/Dto/
RUN dotnet restore Api/Api/Api.csproj

# Copier tout le code source
COPY Api/Api/ ./Api/Api/
COPY Shared/Dto/ ./Shared/Dto/

# Publier le projet
WORKDIR /app/Api/Api
RUN dotnet publish -c Release -o /app/out

# Étape 2 : Runtime
FROM mcr.microsoft.com/dotnet/aspnet:8.0
WORKDIR /app
COPY --from=build /app/out .

ENTRYPOINT ["dotnet", "Api.dll"]