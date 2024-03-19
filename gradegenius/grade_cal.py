#!/bin/python3
'''Grade Calculator'''

def grade_cal(grades={}):
	'''Calculates GPA based on given grades'''
	grade_val = { 'A': 5, 'B': 4, 'C': 3, 'D': 2, 'E': 1, 'F': 0 }
	for key, value in grades:
		if type(key) is not str:
			raise TypeError(f'{key} is not a valid grade. 
				   			All grades should be letters')
		if key.upper() not in grade_val:
			raise ValueError(f'{key} is not a valid grade.
							Enter a grade between A - F')
		if type(eval(value)) is not int:
			raise TypeError(f'{key} is not a valid credit hour. 
				   			Hours should be whole numbers')
	quality_point = 0
	credit_hours = 0
	for grade, hour in grades.item():
		credit_hours += eval(hour)
		quality_point += grade_val[grade] * eval(hour)
	return quality_point / credit_hours