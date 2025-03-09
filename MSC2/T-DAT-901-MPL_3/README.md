# 📊 Projet Web Big-Data de Suivi de Cryptomonnaies 🪙🚀

## 📋 Description
Ce projet a pour objectif de créer une application web big-data permettant de suivre l'évolution en temps réel des cryptomonnaies, notamment le **Bitcoin** et l'**Ethereum**. L'application collecte en continu les données via des API externes, les traite pour fournir des analyses, et les visualise dynamiquement dans des graphiques adaptés 📈📉.

### 🔑 Fonctionnalités principales
- **🔄 Collecte continue** des données sur plusieurs cryptomonnaies à partir d'API externes.
- **⚡ Traitement des données en temps réel** pour fournir des analyses sur l'évolution des cours.
- **📊 Affichage dynamique** des analyses sous forme de graphiques interactifs avec échelle temporelle.
- **🌐 Architecture scalable** basée sur Kafka pour supporter des volumes importants de données.

## 🏗️ Architecture
L'architecture suit le paradigme **producer/consumer** et est optimisée pour la performance en temps réel. Voici les principales composantes du projet :

- **🏭 Producers Kafka** : Les données sur les cryptomonnaies sont collectées à partir de plusieurs API externes, formatées en amont dans les producers, et publiées dans des topics Kafka.
- **🗃️ Cluster Kafka** : Les données sont distribuées dans plusieurs partitions pour chaque cryptomonnaie afin de gérer des volumes importants de données. Un système de réplication assure la haute disponibilité des données.
- **👥 Consumers Kafka** : Les consumers récupèrent les données depuis Kafka pour les afficher en temps réel dans des graphiques.
- **🔌 WebSocket (en option)** : Permet la diffusion des analyses en temps réel vers les clients (page web, Grafana, etc.).

## 🛠️ Technologies
Le projet utilise les technologies suivantes :

- **☕ Java 21** : Utilisé pour les producers et les consumers Kafka.
- **🦄 Apache Kafka** : Système de message distribué pour assurer la scalabilité et la performance du traitement des données.
- **⚙️ Spring Boot** : Framework principal pour simplifier le développement, la configuration et le déploiement.
- **🚀 Spring Kafka** : Intégration avec Kafka pour gérer les producers et consumers.
- **📊 Grafana** (ou un client personnalisé) : Pour la visualisation des données en temps réel.
- **🔗 WebSocket** (optionnel) : Permet de diffuser les mises à jour des cours en temps réel vers les clients.

## 🚀 Installation et exécution

### 🔧 Prérequis
- **☕ JDK 21** : Assurez-vous que Java 21 est installé.
- **🦄 Apache Kafka** : Un cluster Kafka doit être configuré et opérationnel.
- **🐘 Maven** : Pour gérer les dépendances du projet.
