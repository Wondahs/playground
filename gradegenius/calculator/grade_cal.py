#!/bin/python3
'''Grade Calculator'''

def grade_cal(grades=[], credit_hours=[]):
    '''Calculates GPA based on given grades'''
    if not grades:
        raise ValueError("Enter Grades")
    if not grades:
        raise ValueError("Enter Credit Hours")
    if len(grades) != len(credit_hours):
        raise ValueError("Unequal number of Grades and Credit Hours")
    grade_val = { 'A': 5, 'B': 4, 'C': 3, 'D': 2, 'E': 1, 'F': 0 }
    for grade, hour in zip(grades, credit_hours):
        if type(grade) is not str:
            raise TypeError(f'{grade} is not a valid grade. '
                    'All grades should be letters')
        if grade.upper() not in grade_val:
            raise ValueError(f'{grade} is not a valid grade. '
                    'Enter a grade between A - F')
        if type(int(hour)) is not int:
            raise TypeError(f'{hour} is not a valid credit hour. '
                    'Hours should be whole numbers')
    quality_point = 0
    total_hours = sum([int(number) for number in credit_hours])
    for grade, hour in zip(grades, credit_hours):
        quality_point += grade_val[grade] * int(hour)
    return quality_point / total_hours
