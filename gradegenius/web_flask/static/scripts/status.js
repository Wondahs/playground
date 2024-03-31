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

navToggle.addEventListener('click', () => {
	let nav = document.querySelector("nav");
	if (nav.style.right === '-450px') {
		console.log("Show nav");
		nav.style.right = '0';
		navToggle.textContent = '\u2716';
		navToggle.style.right = "215px";
	} else {
		nav.style.right = '-450px';
		navToggle.textContent = '\u2630';
		navToggle.style.right = "15px";

	}
});
