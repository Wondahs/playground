#!/usr/bin/python3
'''Module containing User Class'''
from models.base_model import BaseModel, Base, Column, String


class User(BaseModel, Base):
    '''User Class'''
    __tablename__ = "users"
    email: str = Column(String(128), nullable=False)
    password: str = Column(String(128), nullable=False)
    first_name: str = Column(String(128), nullable=False)
    last_name: str = Column(String(128), nullable=False)

    def __init__(self, *args, **kwargs):
        '''Instantiation Method'''
        super().__init__(*args, **kwargs)
