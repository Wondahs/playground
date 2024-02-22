#!/usr/bin/python3
'''Module containing console - the entry point of the command interpreter'''
import cmd
from models.base_model import BaseModel
from models import storage


classes = {"BaseModel": BaseModel}
class HBNBCommand(cmd.Cmd):
	'''Command interpreter class'''
	prompt = "(hbnb) "

	def precmd(self, line: str) -> str:
		'''Formats argument before commands are executed'''
		return super().precmd(line)
	
	def do_show(self, arg):
		'''
		Prints the string representation of an instance 
		based on the class name and id.
		'''
		if not arg:
			print("** class name missing **")
			return
		arg_list = arg.split()
		class_name, obj_id = arg_list[0], arg_list[1]
		if not class_name:
			print("** class name missing **")
			return
		if class_name not in classes.keys():
			print("** class doesn't exist **")
			return
		if not obj_id:
			print("** instance id missing **")
			return
		all = storage.all()
		for key, value in all.items():
			if obj_id in key.split("."):
				print(value)
				return
		print("** no instance found **")
		return

	def do_create(self, arg):
		'''
		Creates a new instance of BaseModel, saves it (to the JSON file)
		and prints the id. Ex: $ create BaseModel.
		'''
		if not arg:
			print("** class name missing **")
			return
		if arg not in classes.keys():
			print("** class doesn't exist **")
			return
		new = eval(f"{arg}()")
		new.save()
		print(new.id)
			

	def do_quit(self, arg):
		'''to exit the program'''
		return True
	
	def do_EOF(self, arg):
		'''to exit the program'''
		return True
	
	def do_help(self, arg: str) -> bool | None:
		'''Shows help for commands'''
		return super().do_help(arg)

if __name__ == "__main__":
	HBNBCommand().cmdloop()