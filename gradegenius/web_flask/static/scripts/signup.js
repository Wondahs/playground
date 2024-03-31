let submitButton = document.getElementById("signup-submit");
let formElement = document.getElementById("signup-form");
let postDocument = {};


formElement.addEventListener('submit', event => {
	event.preventDefault();
})
submitButton.addEventListener('click', () => {
	let signupForm = document.getElementById("signup-form");

	let formInputs = signupForm.getElementsByTagName("input");
	for (i = 0; i < formInputs.length; i++) {
		postDocument[formInputs[i].name] = formInputs[i].value;
	}
	console.log(postDocument);

	let documentJson = JSON.stringify(postDocument)

	fetch('http://localhost:5001/api/v1/users', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: documentJson
    }).then(response => {
        // Handle response as needed
        console.log(response);
		window.location.href = "/signup-success"
    }).catch(error => {
        console.error('Error:', error);
    });
});
