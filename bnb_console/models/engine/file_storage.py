#!/usr/bin/python3
"""Module containing FileStorage class"""
import json
from models.base_model import BaseModel
from models.user import User
from models.amenity import Amenity
from models.city import City
from models.place import Place
from models.review import Review
from models.state import State


class FileStorage:
    """Class handling files and storage"""
    __file_path = "file.json"
    __objects = {}

    def all(self):
        """Returns __objects"""
        return FileStorage.__objects

    def new(self, obj):
        """
        Sets in __objects the obj with key <obj class name>.id
    """
        key = f"{obj.__class__.__name__}.{obj.id}"
        FileStorage.__objects[key] = obj

    def save(self):
        """
        Serializes __objects to the JSON file (path: __file_path).
        """
        objects = FileStorage.__objects
        dict_objects = {}
        for obj_key in objects.keys():
            obj = objects[obj_key]
            dict_objects[obj_key] = obj.to_dict()

        with open(FileStorage.__file_path, 'w', encoding="utf-8") as file:
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
