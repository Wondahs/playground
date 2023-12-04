#!/usr/bin/python3
import cmd

class Cmd_line(cmd.Cmd):

    prompt = "> "

    def do_greet(self, name):
        """ Greets specified name."""
        if name:
            print(f"Hello, {name}!")
        else:
            print("Hi!")

    def help_greet(self):
        """Prints help for greet module."""
        print("Syntax: greet <name>")
        print("Greets specified name.")

    def do_EOF(self, line):
        """Exits the program on EOF."""
        return True

    def do_quit(self, line):
        """Quits the program"""
        return True

if __name__ == "__main__":
    Cmd_line().cmdloop()
