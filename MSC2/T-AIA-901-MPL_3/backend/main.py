from fastapi import FastAPI, File, UploadFile

from services.process_manager import ProcessManager

app = FastAPI()

process_manager = ProcessManager()


@app.get("/")
def hello():
    return {"message": "Hello World"}


@app.post("/predict")
def predict(query: str, service: str):
    return {"result": process_manager.process(query, service)}

@app.post("/add_data")
def add_data(file: UploadFile = File(...)):
    process_manager.add_data(file)
    return "Ok let's go"