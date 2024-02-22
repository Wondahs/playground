#!/usr/bin/python3
'''Module containing Place Class'''
from models.base_model import BaseModel


class Place(BaseModel):
    '''Place Class'''
    city_id: str = ""
    user_id: str = ""
    name: str = ""
    description: str = ""
    number_rooms: int = 0
    number_bathrooms: int = 0
    max_guest: int = 0
    price_by_night: int = 0
    latitude: float = 0.0
    longitude: float = 0.0
    amenity_ids: list = []

    def __init__(self, *args, **kwargs):
        '''Instantiation Method'''
        super().__init__(*args, **kwargs)
