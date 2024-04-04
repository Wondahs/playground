let status_url = "http://localhost:5001/api/v1/status"

fetch(status_url)
	.then(response => {
		if (!response.ok) {
			throw new Error("Status Unavailable")
		}
		return response.json();
	})
	.then(data => {
		if (data["status"] === "ok") {
			let statusDiv = document.getElementById("status")
			statusDiv.style.color = 'green';
			statusDiv.style.backgroundColor = 'white';
			console.log("OK!")
		} else {
			statusDiv.style.color = 'white';
			statusDiv.style.backgroundColor = 'red';
		}
	})
	.catch(error => {
		console.error("Fetch error")
	})

let navToggle = document.getElementById("nav-toggle");
let nav = document.querySelector("nav");
nav.style.right = '-450px';

navToggle.addEventListener('click', () => {
	if (nav.style.right === '-450px') {
		console.log("Show nav");
		nav.style.right = '0';
		nav.style.top = '10px';
		navToggle.textContent = '\u2716';
		navToggle.style.right = "215px";
	} else {
		nav.style.right = '-450px';
		nav.style.top = '7px';
		navToggle.textContent = '\u2630';
		navToggle.style.right = "15px";
	}
});
