#!/usr/bin/python3
'''Module containing DBStorage Class'''
from os import getenv
from sqlalchemy.orm import sessionmaker
from sqlalchemy import create_engine
from models.base_model import Base


user = getenv('HBNB_MYSQL_USER')
password = getenv('HBNB_MYSQL_PWD')
host = getenv('HBNB_MYSQL_HOST')
db = getenv('HBNB_MYSQL_DB')
class DBStorage:
    '''Engine to handle database storage'''
    __engine = None
    __session = None

    def __init__(self):
        '''Starts engine'''
        self.__engine = create_engine('mysql+mysqldb://{}:{}@{}/{}'
                .format(user, password, host, db),
                pool_pre_ping=True)
        Base.metadata.create_all(self.__engine)
