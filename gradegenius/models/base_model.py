#!/bin/python3
'''Module containing BaseModel'''
from uuid import uuid4
from datetime import datetime

class BaseModel:
    '''Base Class'''
    def __init__(self, **kwargs):
        '''Instantiation method'''
        if kwargs:
            for key, value in kwargs.items():
                setattr(self, key, value)
            if kwargs.get("created_at", None):
                self.created_at = datetime.strptime(kwargs["created_at"])
            else:
                self.created_at = datetime.utcnow()
            if kwargs.get("updated_at", None):
                self.updated_at = datetime.strptime(kwargs["updated_at"])
            else:
                self.updated_at = datetime.utcnow()
        else:
            self.id = str(uuid4())
            self.created_at = datetime.utcnow()
            self.updated_at = datetime.utcnow()
    def __str__(self):
        '''Returns a string representation of BaseModel'''
        class_name = self.__class__.__name__
        return f"{class_name}.{self.id}: {self.__dict__}"
