from infrastructure.db import get_db
from requests import Session

from model.route import Route


class RouteRepository:
    def __init__(self):
        self.db: Session = next(get_db())

    def get_all_routes(self):
        return self.db.query(Route).all()

    def create_route(self, route: Route):
        try:
            self.db.add(route)
            self.db.commit()
            self.db.refresh(route)
        except Exception as e:
            self.db.rollback()
            raise e
        return route

    def delete_route(self, route: Route):
        try:
            self.db.delete(route)
            self.db.commit()
        except Exception as e:
            self.db.rollback()
            raise e
        return route

    def get_all_starts(self, city):
        return (
            self.db.query(Route.Departure)
            .filter(Route.Departure_City.ilike(f"%{city}%"))
            .distinct()
            .all()
        )

    def get_all_ends(self, city):
        return (
            self.db.query(Route.Arrival)
            .filter(Route.Arrival_City.ilike(f"%{city}%"))
            .distinct()
            .all()
        )
