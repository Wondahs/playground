from models import storage
from models.user import User
from models.courses import Courses
from api.v1.views import app_views
from flask import jsonify, abort, make_response

@app_views.route("/courses", methods=["GET"], strict_slashes=False)
def all_courses():
	"""Returns all courses"""
	courses = []
	courses_objs = storage.all(Courses)
	for key, course in courses_objs.items():
		courses.append(course.to_dict())
	return make_response(jsonify(courses), 200)

@app_views.route("/courses/<course_id>",
				 methods=["GET"],
				 strict_slashes=False)
def get_course(course_id):
	"""Get a specific course"""
	course = storage.get(Courses, course_id)
	if course == None:
		abort(404)
	return jsonify(course.to_dict())

@app_views.route("/courses/<course_id>",
				 methods=["DELETE"],
				 strict_slashes=False)
def delete_course(course_id):
	"""Delete a course"""
	course = storage.get(Courses, course_id)
	print(course)
	if not course:
		abort(404)
	course.delete()
	storage.save()
	return make_response('', 200)
