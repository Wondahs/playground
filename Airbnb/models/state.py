#!/usr/bin/python3
'''Module containing State Class'''
from models.base_model import BaseModel, Base, Column, String
from sqlalchemy.orm import Relationship
from os import getenv
from models.city import City

class State(BaseModel, Base):
    '''State Class'''
    __tablename__ = "states"
    name: str = Column(String(128), nullable=False)
    # Define One-to-Many relationship with City
    cities = Relationship("City", backref="state", cascade="all, delete-orphan")

    def __init__(self, *args, **kwargs):
        '''Instantiation Method'''
        super().__init__(*args, **kwargs)

    if getenv("HBNB_TYPE_STORAGE") != "db":
        @property
        def cities(self):
            from models import storage
            '''
            Returns the list of City instances
            with state_id equals to the current State.id
            '''
            cities_list = []
            for key, obj in storage.all(City).items():
                if obj.state_id == self.id:
                    cities_list.append(obj)
            return cities_list
