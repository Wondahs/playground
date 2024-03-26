#!/bin/python3
'''Module containing flask app'''
from flask import Flask, render_template


app = Flask(__name__)


@app.route("/", strict_slashes=False)
def home():
    '''Home Page'''
    return "Hello World!"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port="3000")
