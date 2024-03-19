#!/bin/python3
'''Console program for grade genius'''
from calculator.grade_cal import grade_cal
from models.user import User

def create_user():
	'''Creates User for demo testing'''
	new_user = User()
	name = input("Enter Name: ")
	new_user.name = name
	username = input("Enter Username: ")
	new_user.username = username
	school = input("Enter School: ")
	new_user.school = school
	print("Account successfully created")
	return new_user

print('*' * 30)
print("\tWelcome to GradeGenius")
create_prompt = input("Do you wanna create an account? Y / N: ")
if create_prompt.upper == 'Y':
	new_user = create_user()
	print("Your name is {}.\nYour username is {}.\nYour school is {}".format(new_user.name, new_user.username, new_user.school))