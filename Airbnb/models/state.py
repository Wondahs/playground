#!/usr/bin/python3
'''Module containing State Class'''
from models.base_model import BaseModel


class State(BaseModel):
    '''State Class'''
    state_id: str = ""
    name: str = ""

    def __init__(self, *args, **kwargs):
        '''Instantiation Method'''
        super().__init__(*args, **kwargs)
