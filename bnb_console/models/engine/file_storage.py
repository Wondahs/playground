#!/usr/bin/python3
"""Module containing FileStorage class"""
import json


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
        dict_objects = {obj: objects[obj].to_dict() for obj in objects}
        with open(FileStorage.__file_path, 'w', encoding="utf-8") as file:
            json.dump(dict_objects, file)

    def reload(self):
        """
        Deserializes the JSON file to __objects.
        """
        try:
            with open(FileStorage.__file_path, 'r', encoding="utf-8") as file:
                json_objects = json.load(file)
                for obj in json_objects.values():
                    cls_name = obj['__class__']
                    del obj['__class__']
                    self.new(eval(cls_name)(**obj))
        except IOError:
            print("No such file")
            return
