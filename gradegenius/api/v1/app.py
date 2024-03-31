from models import storage
from models.user import User
from models.courses import Courses
from api.v1.views import app_views
from flask import Flask, jsonify, make_response
from flask_cors import CORS

app = Flask(__name__)
app.register_blueprint(app_views)
CORS(app, resources={r"/api/*": {"origins": "*"}})

@app.errorhandler(404)
def not_found(error):
	"""404 error handler"""
	error_msg = {"error": "Not found"}
	return make_response(jsonify(error_msg))

if __name__ == "__main__":
	port = "5001"
	host = "0.0.0.0"
	app.run(host=host, port=port)