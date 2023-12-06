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
        HBNBCommand.class_dict[new_instance.id] = class_name
        print(new_instance.id)

    def do_show(self, args):
        """
        Prints the string representation
        of an instancebased on the class name and id.
        Ex: $ show BaseModel 1234-1234-1234.
        """
        if not args:
            print("** class name missing **")
            return
        args_list = args.split()
        class_name = args_list[0]
        if class_name not in HBNBCommand.class_list:
            print("** class doesn't exist **")
            return
        if len(args_list) < 2:
            print("** instance id missing **")
            return
        class_id = args_list[1]
        if (class_id in HBNBCommand.class_dict.keys() and
                HBNBCommand.class_dict[class_id] == class_name):
            key = f"{class_name}.{class_id}"
            print(f"{HBNBCommand.class_obj[key]}")
        else:
            print("** no instance found **")

    def do_destroy(self, args):
        """
        Deletes an instance based on the class name
        and id (save the change into the JSON file).
        Ex: $ destroy BaseModel 1234-1234-1234
        """
        if not args:
            print("** class name missing **")
            return
        args_list = args.split()
        class_name = args_list[0]
        if class_name not in HBNBCommand.class_list:
            print("** class doesn't exist **")
            return
        if len(args_list) < 2:
            print("** instance id missing **")
            return
        class_id = args_list[1]
        if (class_id in HBNBCommand.class_dict.keys()
            and HBNBCommand.class_dict[class_id] == class_name):
            key = f"{class_name}.{class_id}"
            del storage.all()[key]
            del HBNBCommand.class_dict[class_id]
            storage.save()
        else:
            print("** no instance found **")

    def do_EOF(self, line):
        """Exits the program on EOF."""
        return True

    def do_quit(self, line):
        """Quits the program"""
        return True

    def emptyline(self):
        """Do nothing upon receiving emptyline"""
        pass


if __name__ == '__main__':
    HBNBCommand().cmdloop()
