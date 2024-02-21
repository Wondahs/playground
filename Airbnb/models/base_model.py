#!/usr/bin/python3
'''
Module containing class BaseModel
that defines all common attributes/methods for other classes.
'''
import uuid
from datetime import datetime
from models import storage

class BaseModel:
    '''BaseModel class'''
    id:str = str(uuid.uuid4())
    created_at = datetime.now()
    updated_at = datetime.now()

    def __init__(self, *args, **kwargs):
        '''Instantiation method.'''
        if kwargs:
            self.__dict__.update(kwargs)
            if self.__dict__.get("class"):
                del self.__dict__["class"]
            self.__dict__["created_at"] = datetime.strptime(self.__dict__["created_at"], "%Y-%m-%dT%H:%M:%S.%f")
            self.__dict__["updated_at"] = datetime.strptime(self.__dict__["updated_at"], "%Y-%m-%dT%H:%M:%S.%f")
            storage.new(self)
        else:
            self.id = str(uuid.uuid4())
            self.created_at = datetime.now()
            storage.new(self)

    def __str__(self):
        '''
        Prints string representation of Class
        in the format [<class name>] (<self.id>) <self.__dict__>.
        '''
        class_name = self.__class__.__name__
        return (f"[{class_name}] ({self.id}) {self.__dict__}")


    def save(self):
        '''
        updates the public instance attribute
        updated_at with the current datetime
        '''
        self.updated_at = datetime.now()
        storage.save()


    def to_dict(self):
        '''
        returns a dictionary containing all keys/values
        of __dict__ of the instance.
        '''
        dictionary = {}
        dictionary.update(self.__dict__)
        dictionary["__class__"] = self.__class__.__name__
        dictionary["updated_at"] = self.updated_at.isoformat()
        dictionary["created_at"] = self.created_at.isoformat()
        return dictionary
