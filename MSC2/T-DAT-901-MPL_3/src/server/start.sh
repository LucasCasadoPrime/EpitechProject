#!/bin/bash

docker compose -f docker-compose.infrastructure.yml up -d --build

echo "Creating topic..."

command = "sleep 10 && /opt/kafka/bin/kafka-topics.sh --bootstrap-server localhost:19092 --create --topic card-price --partitions 3 --replication-factor 2"
docker exec -it broker-1 sh -c "$command"

echo "Waiting for brokers..."
sleep 20

docker compose -f docker-compose.metrics.yml up -d --build
docker compose -f docker-compose.application.yml up -d --build