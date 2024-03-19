#!/usr/bin/python3
'''Web framework using Flask'''
from flask import Flask, render_template
from models import storage
from models.state import State
from models.amenity import Amenity


app = Flask(__name__)


@app.teardown_appcontext
def app_teardown(exception):
    '''Closes storage'''
    storage.close()

@app.route("/hbnb_filters", strict_slashes=False)
def states_list():
    '''Displays states'''
    states_obj = list(storage.all(State).values())
    sorted_states = sorted(states_obj, key=lambda x: x.name)
    amenities_list = list(storage.all(Amenity).values())
    sorted_amenities = sorted(amenities_list, key=lambda x: x.name)
    return render_template("hbnb_filters.html",
                           state_list=sorted_states,
                           amenities=sorted_amenities)

if __name__ == "__main__":
    host = "0.0.0.0"
    port = 5000
    app.run(host=host, port=port, debug=True)
