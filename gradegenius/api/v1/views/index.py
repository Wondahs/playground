#!/usr/bin/python3
'''API for status'''
from models.user import User
from models.courses import Courses
import json
from api.v1.views import app_views
from flask import make_response, abort, request, jsonify
from models import storage

@app_views.route("/status", methods=["GET"],
				  strict_slashes=False)
def status():
	"""API status"""
	status = {"status": "ok"}
	return make_response(jsonify(status), 200)

@app_views.route("/stats", methods=["GET"],
				  strict_slashes=False)
def stats():
	"""Stats"""
	stats = {
		"Users": f"{storage.count(User)}",
		"Courses": f"{storage.count(Courses)}"
	}
	return make_response(jsonify(stats), 200)
