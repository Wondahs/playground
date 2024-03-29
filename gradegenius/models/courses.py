'''Module containing Courses class'''
from models.base_model import BaseModel

class Courses(BaseModel):
	"""Courses class"""
	user_id = ""
	name = ""
	credit_hour = ""
	grade = ""
	year = ""
	semester = ""
	