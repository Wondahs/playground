#!/bin/python3
"""Module containing FileStorage"""
import json
from models.user import User


class FileStorage:
    """File Storage Class"""
    __objects = {}
    __file_path = "genius.json"

    def new(self, obj):
        """Adds new obj to storage"""
        key = f"{obj.__class__.__name__}.{obj.id}"
        self.__objects[key] = obj
    
    def all(self, obj):
        """
        Returns all objects of type <obj> if <obj> is specified,
        or all objects in storage.
        """
        if obj:
            obj_dict = {}
            for key, value in self.__objects:
                if type(value) == type(obj):
                    key = f"{obj.__class__.__name__}.{obj.id}"
                    obj_dict[key] = obj
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
                for obj in json_objects.values():
                    cls_name = obj['__class__']
                    del obj['__class__']
                    self.new(eval(cls_name)(**obj))
        except Exception:
            return
