#!/bin/python3
'''Test Calculator'''
from calculator.grade_cal import grade_cal

grade = ['A', 'C', 'B', 'A', 'D']
hours = [4, 3, 5, 4, 1]

print("Your GPA is {:.2f}".format(grade_cal(grade, hours)))
