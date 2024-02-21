#!/usr/bin/python3
'''
    Module containing class FileStorage.
'''
import json


class FileStorage:
    '''
    FileStorage that serializes instances to a JSON file
    and deserializes JSON file to instances.
    '''
    __file_path = "file.json"
    __objects = {}

    def all(self):
        ''': returns the dictionary __objects'''
        return self.__objects

    def new(self, obj):
        '''sets in __objects the obj with key <obj class name>.id.'''
        from models.base_model import BaseModel

        key = f"{obj.__class__.__name__}.{obj.id}"
        self.__objects[key] = obj

    def save(self):
        '''serializes __objects to the JSON file (path: __file_path)'''
        objects = {}
        for key, value in self.__objects.items():
            objects[key] = value.to_dict()
        jsondump = json.dumps(objects)
        try:
            with open(self.__file_path, 'w', encoding='utf-8') as jsonfile:
                jsonfile.write(jsondump)
        except IOError:
            print("Error Writing to file")

    def reload(self):
        from os import path
        from models.base_model import BaseModel

        classes = {"BaseModel": BaseModel}
        if path.exists(self.__file_path):
            with open(self.__file_path, 'r', encoding='utf-8') as jsonfile:
                dicts = json.load(jsonfile)
            for key, value in dicts.items():
                class_name = value["__class__"]
                if class_name in classes:
                    obj = eval(f"{class_name}(**{value})")
                self.__objects[key] = obj
            self.save()
