#!/bin/python3
'''Test Calculator'''
from calculator.grade_cal import grade_cal

grade = ['A', 'C', 'B', 'A']
hours = [4, 3, 5, ]

print("Your GPA is {:.3f}".format(grade_cal(grade, hours)))
