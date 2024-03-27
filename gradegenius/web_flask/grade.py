#!/bin/python3
"""Module containing Flask app"""
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/", strict_slashes=False)
def home():
	"""Serves Landing Page"""
	return render_template("home.html",
						   title='Home',
						   css_file='styles/home.css')

@app.route("/login", strict_slashes=False)
def login():
	"""Serves Login Page"""
	return render_template("login.html",
						   title='Login',
						   css_file='styles/login.css')

@app.route("/signup", strict_slashes=False)
def signup():
	"""Serves Login Page"""
	return render_template("signup.html",
						   title='Signup',
						   css_file='styles/login.css')

@app.route("/calculate", strict_slashes=False)
def calculate():
	"""Serves Calculator Page"""
	return render_template("calculator.html",
						   title='Calculate',
						   css_file='styles/calculator.css',
						   script='scripts/calculator.js')

@app.route("/about", strict_slashes=False)
def about():
	"""Serves About Page"""
	return render_template("about.html",
						   title="About",
						   css_file="styles/about.css",)

if __name__ == "__main__":
	host = "0.0.0.0"
	port = "5000"
	app.run(host=host, port=port, debug=True)
