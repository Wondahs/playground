from models import storage
from models.user import User
from models.courses import Courses
from api.v1.views import app_views
from flask import jsonify, abort, make_response, request

@app_views.route("/courses", methods=["GET"], strict_slashes=False)
def all_courses():
	"""Returns all courses"""
	courses = []
	courses_objs = storage.all(Courses)
	for key, course in courses_objs.items():
		courses.append(course.to_dict())
	return make_response(jsonify(courses), 200)

@app_views.route("/users/<user_id>/courses/",
				 methods=["GET"],
				 strict_slashes=False)
def get_courses(user_id):
	"""Get all courses for a user"""
	courses = storage.all(Courses)
	user_courses = []
	for key, course in courses.items():
		if course.user_id == user_id:
			user_courses.append(course.to_dict())
	return jsonify(user_courses)

@app_views.route("/users/<user_id>/courses/<course_id>",
				 methods=["GET"],
				 strict_slashes=False)
def get_course(course_id, user_id):
	"""Get a specific course for a user"""
	courses = storage.all(Courses)
	user_course = None
	for key, course in courses.items():
		if course.user_id == user_id and course.id == course_id:
			user_course = course
	if user_course == None:
		abort(404)
	return jsonify(user_course.to_dict())

@app_views.route("/users/<user_id>/courses/<course_id>",
				 methods=["DELETE"],
				 strict_slashes=False)
def delete_course(user_id, course_id):
	"""Delete a course"""
	courses = storage.all(Courses)
	user_course = None
	for key, course in courses.items():
		if course.user_id == user_id and course.id == course_id:
			user_course = course
	if not user_course:
		abort(404)
	user_course.delete()
	storage.save()
	return make_response('', 200)

@app_views.route("/users/<user_id>/courses/",
				 methods=["POST"],
				 strict_slashes=False)
def create_course(user_id):
	"""Creates a new course"""
	if not request.is_json:
		abort(400, "Not a Json")
	data = request.get_json()
	new_course = Courses(**data)
	new_course.user_id = user_id
	new_course.save()
	return make_response(jsonify(new_course.to_dict()), 201)

@app_views.route("/users/<user_id>/courses/<course_id>",
				 methods=["PUT"],
				 strict_slashes=False)
def update_course(user_id, course_id):
	"""Updates a course"""
	if not request.is_json:
		abort(400, "Not a Json")

	courses = storage.all(Courses)
	user_course = None
	for key, course in courses.items():
		if course.user_id == user_id and course.id == course_id:
			user_course = course
	if not user_course:
		abort(404)
	data = request.get_json()
	for key, value in data.items():
		if key not in ["id", "created_at", "updated_at", "user_id"]:
			setattr(user_course, key, value)
	user_course.save()
	return make_response(jsonify(course.to_dict()), 200)
