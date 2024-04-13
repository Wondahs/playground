let subscribeButton = document.getElementById("subscribe-button");
let dissmissButton = document.getElementById("dismiss-button");
let signupDiv = document.getElementById("signup-div");
let successDiv = document.getElementById("success-div");
let emailContent = document.getElementById("email");
let errorMsg = document.getElementById("error-msg");
let userEmail = document.getElementById("user-email");


subscribeButton.addEventListener('click', () => {
	let emailContent = document.getElementById("email");
	let valid = emailValid(emailContent.value);
	
	console.log(valid);
	if (valid) {
		signupDiv.style.display = "none";
		successDiv.style.display = "flex";
		userEmail.textContent = emailContent.value;
	} else {
		emailContent.classList.add("input-error");
		errorMsg.textContent = "Valid email required";
	}
});

dissmissButton.addEventListener('click', () => {
	signupDiv.style.display = "flex";
	emailContent.value = "";
	successDiv.style.display = "none";
});

emailContent.addEventListener('input', (event) => {
	let email = event.target;

	console.log(email.value);
	email.classList.remove("input-error");
	errorMsg.textContent = "";
});

function emailValid (email) {
	const emailRegex = /^[\w](?!.*\.{2,})[\w\d\-_\.?]+@(?!.*\.{2,})[\w\d.-]+\.[\w]{2,}$/

	return emailRegex.test(email);
}