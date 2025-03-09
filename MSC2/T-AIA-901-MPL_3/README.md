# Project Overview

Before reading this Project Overview, you can view our last models pushed on Hugging Face :

## NER -> [T-AIA-CamemBERT-NER-V2](https://huggingface.co/Crysy-rthomas/T-AIA-CamemBERT-NER-V2)

## TEXT_CLASSIFICATION -> [T-AIA-DISTILCAMEMBERT-BASE-TEXT-CLASSIFICATION](https://huggingface.co/InesPL84/T-AIA-DISTILCAMEMBERT-BASE-TEXT-CLASSIFICATION)

This project is a comprehensive system that includes backend, frontend, and various specialized modules for different functionalities. Below is an overview of the project structure and its components.

## Backend -> http://51.68.191.204:8000/docs#/

The backend directory contains the core server-side code, including:

- **Alembic**: Database migrations.
- **Docker**: Docker configuration files.
- **Infrastructure**: Infrastructure-related code.
- **Main.py**: Entry point for the backend application.
- **Model**: Data models.
- **Repositories**: Data access layer.
- **Services**: Business logic layer.

## Frontend -> http://51.68.191.204:8501/

The frontend directory contains the client-side code, including:

- **Streamlit.py**: Streamlit application for the frontend.
- **Requirements.txt**: Dependencies for the frontend.

## PATHFINDER

The PATHFINDER directory includes scripts and data related to pathfinding algorithms:

- **getcity_v2.py**: Updated city retrieval script.
- **getcity.py**: Original city retrieval script.
- **pathfinder.py**: Pathfinding logic.
- **timetables.csv**: Original timetables data.
- **timetables_modified.csv**: Modified timetables data.

## STT_NER_LLM

The STT_NER_LLM directory includes scripts and data for speech-to-text and named entity recognition using large language models:

- **data_generator_ner.py**: Data generator for NER.
- **demo_ner_v2.py**: Updated NER demo script.
- **demo_ner.py**: Original NER demo script.
- **demo_wisper.py**: Whisper model demo script.
- **firework_service.py**: Firework service script.
- **.env**: Environment variables.
- **data/**: Data directory.
- **ner_model/**: Named entity recognition model.

## STT_WITH_VOSK

The STT_WITH_VOSK directory contains scripts for speech-to-text using the Vosk model:

- **SNCF.py**: Script for processing SNCF data.

## TEXT_CLASSIFICATION

The TEXT_CLASSIFICATION directory includes scripts and data for binary text Classification, using fine-tuning :

- **text_classification.ipynb**: Complete notebook used for Classification.

- **data_generator_classification.py**: Data generator for Classification.

- **demo_classifier.py**: Original Classification demo script.

- **travel_sentences.csv**: Dataset with labeled examples for travel and non-travel sentences.

## Getting Started

### Prerequisites

- Docker
- Python 3.x
- Streamlit

### Installation

1. Clone the repository:
    ```sh
    git clone <repository-url>
    ```

2. Navigate to the backend directory and & create environement variable:
    ```sh
    cd backend
    nano .env
    ```
    ```
    DATABASE_URL=postgresql://admin:admin@host.docker.internal:5432/user
    POSTGRES_DB=user
    POSTGRES_PASSWORD=admin
    POSTGRES_USER=admin
    FIREWORKS_API_KEY=firework_api_key
    ```

3.  Start backend:
    ```sh
    docker compose up -d
    ```

4. Navigate to the frontend directory and Start Frontend:
    ```sh
    cd ../frontend
    docker compose up -d
    ```

### Running the Application

1. Start the frontend application:
    ```sh
    cd ../frontend
    streamlit run streamlit.py
    ```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
