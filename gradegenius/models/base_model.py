#!/bin/python3
'''Module containing BaseModel'''
from uuid import uuid4
from datetime import datetime
import models


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
                self.created_at = datetime.now()
            if kwargs.get("updated_at", None):
                self.updated_at = datetime.strptime(kwargs["updated_at"])
            else:
                self.updated_at = datetime.now()
        else:
            self.id = str(uuid4())
            self.created_at = datetime.now()
            self.updated_at = datetime.now()
        models.storage.new(self)
    def __str__(self):
        '''Returns a string representation of BaseModel'''
        class_name = self.__class__.__name__
        return f"{class_name}.{self.id}: {self.__dict__}"
    
    def to_dict(self):
        """Returns dictionary representation of BaseModel instance"""
        dict_cpy = self.__dict__.copy()
        dict_cpy['__class__'] = self.__class__.__name__
        dict_cpy['created_at'] = self.created_at.isoformat()
        dict_cpy['updated_at'] = self.updated_at.isoformat()
        return dict_cpy
    
    def save(self):
        """Updates updated_at"""
        self.updated_at = datetime.now()
        models.storage.save()
