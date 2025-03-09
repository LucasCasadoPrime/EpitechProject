from sqlalchemy import Column, Integer, String
from infrastructure.db import Base


class Route(Base):
    __tablename__ = 'routes'

    trip_id = Column(String, primary_key=True)
    Departure = Column(String)
    Arrival = Column(String)
    Duration = Column(Integer)
    Departure_City = Column(String)
    Arrival_City = Column(String)
    