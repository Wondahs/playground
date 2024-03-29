from models import storage
from models.user import User
from models.courses import Courses
from api.v1.views import app_views
from flask import jsonify, abort, make_response

@app_views.route("/users", methods=["GET"], strict_slashes=False)
def all_users():
	"""Returns all users"""
	users = []
	users_objs = storage.all(User)
	for key, user in users_objs.items():
		users.append(user.to_dict())
	return make_response(jsonify(users), 200)

@app_views.route("/courses/<user_id>",
				 methods=["GET"],
				 strict_slashes=False)
def get_user(user_id):
	"""Get a specific course"""
	user = storage.get(User, user_id)
	if user == None:
		abort(404)
	return jsonify(user.to_dict())

@app_views.route("/courses/<user_id>",
				 methods=["DELETE"],
				 strict_slashes=False)
def delete_user(user_id):
	"""Delete a course"""
	user = storage.get(Courses, user_id)
	if not user:
		abort(404)
	user.delete()
	storage.save()
	return make_response('', 200)
