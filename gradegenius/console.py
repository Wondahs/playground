#!/bin/python3
"""Console program for grade genius"""
from calculator.grade_cal import grade_cal
from models.user import User
import cmd
from models import storage


class GradeGenius(cmd.Cmd):
    """GradeGenius test console"""
    print("Welcome to GradeGenius")
    prompt = "(GradeGenius) "
    def do_quit(self, arg):
        """Quits the program"""
        return True
    
    def do_EOF(self, args):
        """Exits rogram on EOF input"""
        return True

    def do_create(self, arg):
        """Creates new user"""
        new_user = User()
        name = input("Enter Name: ")
        new_user.name = name.title()
        username = input("Enter Username: ")
        new_user.username = username
        school = input("Enter School: ")
        new_user.school = school
        storage.new(new_user)
        storage.save()
        print("Account successfully created")

    def do_calculate(self, arg):
        """Calculates GPA"""
        course_no = int(input("Enter Number of Courses: "))
        grades = []
        hours = []
        for i in range(course_no):
            grade_checked = False
            hour_checked = False
            while not grade_checked:
                grade = input(f"Enter grade for course {i + 1}: ")
                if not grade.isalpha() or grade.upper() not in set('ABCDEF'):
                    print(f"Invalid grade '{grade}'. Grade should be between A and F")
                else:
                    grade_checked = True
                    grades.append(grade.upper())
            while not hour_checked:
                hour = input(f"Enter Credit Hour for course {i + 1}: ")
                if not hour.isnumeric() or int(hour) not in range(1, 7):
                    print(f"Invalid Hour '{hour}'. Hour should be between 1 and 6")
                else:
                    hour_checked = True
                    hours.append(int(hour))
        print("Your GPA is {}".format(grade_cal(grades, hours)))


if __name__ == "__main__":
    GradeGenius().cmdloop()
