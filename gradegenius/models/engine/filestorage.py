#!/bin/python3
"""Module containing FileStorage"""
import json
from models.user import User
from models.courses import Courses


classes = [User, Courses]
class FileStorage:
    """File Storage Class"""
    __objects = {}
    __file_path = "genius.json"

    def new(self, obj):
        """Adds new obj to storage"""
        key = f"{obj.__class__.__name__}.{obj.id}"
        self.__objects[key] = obj
    
    def all(self, obj=None):
        """
        Returns all objects of type <obj> if <obj> is specified,
        or all objects in storage.
        """
        if obj is not None:
            obj_dict = {}
            for key, value in self.__objects.items():
                if obj.__name__ == value.__class__.__name__:
                    key = f"{value.__class__.__name__}.{value.id}"
                    obj_dict[key] = value
            return obj_dict
        return self.__objects
    
    def save(self):
        """
        Serializes __objects to the JSON file (path: __file_path).
        """
        objects = FileStorage.__objects
        dict_objects = {}
        for obj_key in objects.keys():
            obj = objects[obj_key]
            dict_objects[obj_key] = obj.to_dict()

        with open(self.__file_path, 'w', encoding="utf-8") as file:
            json.dump(dict_objects, file)
    
    def reload(self):
        """
        Deserializes the JSON file to __objects.
        """
        try:
            with open(FileStorage.__file_path) as file:
                json_objects = json.load(file)
                for key, obj in json_objects.items():
                    cls_name = obj['__class__']
                    del obj['__class__']
                    new_item = eval(f"({cls_name})(**{obj})")
        except IOError:
            return

    def get(self, cls, id):
        """Retrieves an object with its id"""
        for key, obj in self.all(cls).items():
            if obj.id == id:
                return obj
        return None
    
    def delete(self, obj=None):
        """delete obj from __objects if it’s inside"""
        if obj is not None:
            key = obj.__class__.__name__ + '.' + obj.id
            if key in self.__objects:
                del self.__objects[key]