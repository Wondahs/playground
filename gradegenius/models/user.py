#!/bin/python3
'''Module containing User class'''
from models.base_model import BaseModel

class User(BaseModel):
    '''User class'''
    name = ""
    username = ""
    password = ""
    school = ""
