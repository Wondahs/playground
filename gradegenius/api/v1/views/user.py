from models import storage
from models.user import User
from models.courses import Courses
from api.v1.views import app_views
from flask import jsonify, abort, make_response, request

@app_views.route("/users", methods=["GET"], strict_slashes=False)
def all_users():
	"""Returns all users"""
	users = []
	users_objs = storage.all(User)
	for key, user in users_objs.items():
		users.append(user.to_dict())
	return make_response(jsonify(users), 200)

@app_views.route("/users/<user_id>",
				 methods=["GET"],
				 strict_slashes=False)
def get_user(user_id):
	"""Get a specific course"""
	user = storage.get(User, user_id)
	if user == None:
		abort(404)
	return jsonify(user.to_dict())

@app_views.route("/users/<user_id>",
				 methods=["DELETE"],
				 strict_slashes=False)
def delete_user(user_id):
	"""Delete a User"""
	user = storage.get(User, user_id)
	if not user:
		abort(404)
	user.delete()
	storage.save()
	return make_response('', 200)

@app_views.route("/users",
				 methods=["POST"],
				 strict_slashes=False)
def create_user():
	"""Creates a new User"""
	if not request.is_json:
		abort(400, "Not a Json")
	data = request.get_json()
	new_user = User(**data)
	new_user.save()
	return make_response(jsonify(new_user.to_dict()), 201)

@app_views.route("/users/user_id",
				 methods=["PUT"],
				 strict_slashes=False)
def update_user(user_id):
	"""Updates a User"""
	if not request.is_json:
		abort(400, "Not a Json")

	user = storage.get(User, user_id)
	if not user:
		abort(404)
	data = request.get_json()
	for key, value in data.items():
		if key not in ["id", "created_at", "updated_at"]:
			setattr(user, key, value)
	user.save()
	return make_response(jsonify(user.to_dict()), 200)
