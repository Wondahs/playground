#!/usr/bin/python3
"""Module containing entry point of the command interpreter"""
import cmd
from models.base_model import BaseModel
from models import storage


class HBNBCommand(cmd.Cmd):
    """Entry point of the command interpreter"""
    prompt = "(hbnb) "
    class_obj = storage.all()
    class_dict = {}
    class_list = set()
    for obj in class_obj.values():
        class_dict[obj.id] = obj.__class__.__name__
        class_list.add(obj.__class__.__name__)

    def do_create(self, class_name):
        """
        Creates a new instance of BaseModel,
        saves it (to the JSON file) and prints the id.
        """
        if not class_name:
            print("** class name missing **")
            return
        if class_name not in HBNBCommand.class_list:
            print("** class doesn't exist **")
            return
        new_instance = BaseModel()
        new_instance.save()
        print(new_instance.id)

    def do_show(self, class_name, class_id):
        """
        Prints the string representation
        of an instancebased on the class name and id.
        Ex: $ show BaseModel 1234-1234-1234.
        """
        if not class_name:
            print("** class name missing **")
            return
        if class_name not in HBNBCommand.class_list:
            print("** class doesn't exist **")
            return
        if not class_id:
            print("** instance id missing **")
            return
        if class_dict[class_id] == class_name:
            key = f"{class_name}.{class_id}"
            print("{class_obj[key]}")

    def do_EOF(self, line):
        """Exits the program on EOF."""
        return True

    def do_quit(self, line):
        """Quits the program"""
        return True


if __name__ == '__main__':
    HBNBCommand().cmdloop()
