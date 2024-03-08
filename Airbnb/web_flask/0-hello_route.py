#!/usr/bin/python3
'''Web framework using Flask'''
from flask import Flask, render_template


app = Flask(__name__)


@app.route("/<name>", strict_slashes=False)
def hello(name):
    '''Prints Hello World'''
    return f"Hello {name.replace('_', ' ')}"

@app.route("/number/<int:n>")
def number(n):
    '''Prints number'''
    value = "even" if n % 2 == 0 else "odd"
    return render_template("0-number.html",
                           number=n, value=value)

if __name__ == "__main__":
    host = "0.0.0.0"
    port = 5000
    app.run(host=host, port=port, debug=True)

