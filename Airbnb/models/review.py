#!/usr/bin/python3
'''Module containing Review Class'''
from models.base_model import BaseModel


class Review(BaseModel):
    '''Review Class'''
    place_id: str = ""
    user_id: str = ""
    text: str = ""

    def __init__(self, *args, **kwargs):
        '''Instantiation Method'''
        super().__init__(*args, **kwargs)
