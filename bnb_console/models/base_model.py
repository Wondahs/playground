#!/usr/bin/python3
"""
Module containing Base Model.
"""
import uuid
from datetime import datetime


class BaseModel:
    """ Base Model."""

    def __init__(self):
        """Instantiation method"""
        self.id = str(uuid.uuid4())
        self.created_at = datetime.now()
        self.updated_at = self.created_at

    def save(self):
        """Updates updated_at"""
        self.updated_at = datetime.now()

    def __str__(self):
        """Prints a representation of BaseModel"""
        return f"[BaseModel] ({self.id}) {self.__dict__}"

    def to_dict(self):
        """Returns a dictionary representation of BaseModel"""
        dict_cpy = self.__dict__.copy()
        dict_cpy["__class__"] = self.__class__.__name__
        dict_cpy["created_at"] = self.created_at.isoformat()
        dict_cpy["updated_at"] = self.updated_at.isoformat()
        return dict_cpy
