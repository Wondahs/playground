let submitButton = document.getElementById("signup-submit"); // Get submit button
let formElement = document.getElementById("signup-form"); // Get signup form
let postDocument = {};
let username = document.getElementById("username"); // Retrieve username
let formInputs = formElement.querySelectorAll('input'); //Retrieve all input elements in form
let formOK = false; // Variable that checks if form is okay to be submitted when user inputs a valid username


// Add event listeners to each input element in form element.
// This disables submit button until all fields are filled.
formInputs.forEach(input => {
    input.addEventListener('input', submitSwitch);
});

// Function that enables or disables submit button depending on if all input elements have been filled.
function submitSwitch() {
    const allFilled = Array.from(formInputs).every(input => input.value.trim() !== '');
    submitButton.classList.toggle("button-disabled", !allFilled || !formOK);
    submitButton.disabled = !allFilled || !formOK
}

// Prevents default behavior of form. This ensures that form credentials aren't displayed
// in the url bar of the browser.
formElement.addEventListener('submit', event => {
	event.preventDefault();
})

// Add event listener to submit button. When the button is clicked, it sends a post request to the
// backend API for creation of new user.
submitButton.addEventListener('click', () => {
	let signupForm = document.getElementById("signup-form");

	let formInputs = signupForm.getElementsByTagName("input");
	for (i = 0; i < formInputs.length; i++) {
		postDocument[formInputs[i].name] = formInputs[i].value.replace(/\s+/g, '').trim();
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
        console.log(response);
		window.location.href = "/signup-success"
    }).catch(error => {
        console.error('Error:', error);
    });
});

// Check if username given by user is unique. If the username already exists,
// this code section displays an eror message and disables submit button.
username.addEventListener('input', async (event) => {
    let username = event.target.value;
    let available = await checkUsername(username);
    let usernameOk = document.getElementById("username-ok");

    usernameOk.textContent = available ? "\u2713 Username Available" : "\u2716 Username Not Available";
    usernameOk.style.color = available ? 'green' : 'red';
    formOK = available;
    submitSwitch();
});

// Checks if <username> is unique.
async function checkUsername(username) {
    try {
        let response = await fetch('http://localhost:5001/api/v1/users');

        if (!response.ok) {
            throw new Error("Network response was not ok");
        }
        let data = await response.json();
        console.log(data);
        for (const obj of data) {
            if (username.toUpperCase() === obj.username.toUpperCase()) {
                return false;
            }
        }
        return true;
    } catch (error) {
            console.error('There was a problem with the fetch operation:', error);
    }
}
