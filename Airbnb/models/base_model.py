#!/usr/bin/python3
'''
Module containing class BaseModel
that defines all common attributes/methods for other classes.
'''
import uuid
from datetime import datetime
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, String, DateTime

Base = declarative_base()


class BaseModel:
    '''BaseModel class'''
    id = Column(String(60), primary_key=True, default=uuid.uuid4, nullable=False)
    created_at = Column(DateTime, default=datetime.utcnow, nullable=False)
    updated_at = Column(DateTime, default=datetime.utcnow, nullable=False)

    def __init__(self, *args, **kwargs):
        '''Instantiation method.'''
        if kwargs:
            self.__dict__.update(kwargs)
            if self.__dict__.get("__class__"):
                del self.__dict__["__class__"]
            self.__dict__["created_at"] = \
                datetime.strptime(self.__dict__["created_at"],
                                  "%Y-%m-%dT%H:%M:%S.%f")
            self.__dict__["updated_at"] = \
                datetime.strptime(self.__dict__["updated_at"],
                                  "%Y-%m-%dT%H:%M:%S.%f")
        else:
            self.id = str(uuid.uuid4())
            self.created_at = datetime.now()
            self.updated_at = datetime.now()
        if self.__dict__.get("_sa_instance_state"):
            del self.__dict__["_sa_instance_state"]

    def __str__(self):
        '''
        Prints string representation of Class
        in the format [<class name>] (<self.id>) <self.__dict__>.
        '''
        class_name = self.__class__.__name__
        return (f"[{class_name}] ({self.id}) {self.__dict__}")

    def save(self):
        from models import storage
        '''
        updates the public instance attribute
        updated_at with the current datetime
        '''
        self.updated_at = datetime.now()
        storage.new(self)
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

    def delete(self):
        from models import storage
        '''
        Deletes the current instance from the storage.
        '''
        storage.delete(self)
