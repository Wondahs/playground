#!/usr/bin/python3
'''Module containing Amenity Class'''
from models.base_model import BaseModel


class Amenity(BaseModel):
	'''Amenity Class'''
	name: str = ""


	def __init__(self, *args, **kwargs):
		'''Instantiation Method'''
		super().__init__(*args, **kwargs)