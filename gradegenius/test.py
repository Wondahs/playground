#!/bin/python3
'''Test Calculator'''
from calculator.grade_cal import grade_cal

grade = {
        'A': '4',
        'C': '3',
        'B': '5',
        'A': '2'}

print("Your GPA is {}".format(grade_cal(grade)))
