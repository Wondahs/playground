#!/usr/bin/python3
'''Module containing User Class'''
from models.base_model import BaseModel


class User(BaseModel):
	'''User Class'''
	email: str = ""
	password: str = ""
	first_name: str = ""
	last_name: str = ""

	def __init__(self, *args, **kwargs):
		'''Instantiation Method'''
		super().__init__(*args, **kwargs)
