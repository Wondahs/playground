#!/bin/python3
"""Console program for grade genius"""
from calculator.grade_cal import grade_cal
from models.user import User
from models.courses import Courses
import cmd
from models import storage


classes = [User, Courses]
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
        args = arg.split()
        if len(args) < 1:
            print("Class Name not included")
            return
        new_class = args[0]
        new_item = eval(f"{new_class}")
        if new_item in classes:
            if new_item is not classes[0] and len(args) < 2:
                print("Class Name not included")
            new_obj = eval(f"{new_class}()")
            if new_item is not classes[0]:
                user_id = args[1]
                new_obj.user_id = user_id
            storage.new(new_obj)
            storage.save()
            print(new_obj.id)
        else:
            print("Invalid class")
            return

    def do_all(self, arg):
        all = []
        if arg:
            class_name = arg.split()[0]
            print(class_name)
            clss = eval(class_name)
            for key, obj in storage.all(clss).items():
                all.append(obj.to_dict())
        else:
            for key, val in storage.all().items():
                all.append(val.to_dict())
        print(all)

    def do_calculate(self, arg):
        """Calculates GPA"""
        number_checked = False
        while not number_checked:
        
            courses = input("Enter Number of Courses: ")
            if not courses.isnumeric():
                print("Enter a number")
            else:
                number_checked = True
                course_no = int(courses)
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
