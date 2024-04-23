// Select needed elements
let steps = Array.from(document.querySelectorAll('[class^="step-"]')).filter(element => /\d+/.test(element.className.split('-')[1])); // Select registration steps
let next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next button'); // Select next button depending on screen size
let back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back button'); // Select back button depending on screen size
let currentStepCount = 1; // Step count
let currentStep = document.querySelector(`.step-${currentStepCount}`); // Current step
let footer = document.getElementById("footer");
let stepOneInputs = document.querySelectorAll('.step-1 input');
let stepTwoInputs = document.querySelectorAll('.step-2 input[name="plan"]');
let stepThreeInputs = document.querySelectorAll('.step-3 input')
let changePlan = document.getElementById("changePlan");
let stepButton = document.getElementById(`button-${currentStepCount}`);


// Initialization
back.style.display = "none";
back.style.backgroundColor = "transparent";
back.style.color = "gray";
stepButton.style.backgroundColor = "hsl(228, 100%, 84%)";
stepButton.style.color = "hsl(213, 96%, 18%)";
// Temporarily disable next button
next.classList.add("dim-button");
next.disabled = true;
next.textContent = currentStepCount === 4 ? "Confirm" : "Next Step";

// Update next and back buttons depending on screen size and add necessary event listeners
window.addEventListener('resize', () => {
	next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next button');
	back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back button');
	footer.style.display = window.innerWidth < 768 && currentStepCount < 5 ?"flex" : "none"; // Hide footer if mobile screen.

	// Temporarily hide all steps
	hideSteps(); 

	// Add event listeners to next and back buttons
	next.addEventListener('click', nextStep);
	back.addEventListener('click', prevStep);

	// Buttons properties
	back.style.display = currentStepCount > 1 ? "flex" : "none";
	back.style.backgroundColor = "transparent";
	back.style.color = "gray";

	// Hide buttons if at step 5
	if (currentStepCount === 5){
		back.style.display = "none";
		next.style.display = "none";
	}
	next.textContent = currentStepCount === 4 ? "Confirm" : "Next Step";

	// Display current step
	currentStep = document.querySelector(`.step-${currentStepCount}`);
	currentStep.style.display = 'flex';

	// Check if necessary details have been given depending on step
	allFilled();
	planClicked();
});

// Add event listener for next and back buttons
next.addEventListener('click', nextStep);
back.addEventListener('click', prevStep);

// Event listener to allow user change their plan
changePlan.addEventListener('click', planChange);

// Hide all steps and show only curent step
hideSteps();
currentStep.style.display = 'flex';

// Ensure that all required input fields in steps
// are filled before next button is activated.
stepOneInputs.forEach(element => {
	element.addEventListener('input', allFilled);
});

stepTwoInputs.forEach(element => {
	element.addEventListener('change', planClicked);
});

stepThreeInputs.forEach(element => {
	element.addEventListener('change', addOnClicked);
});

// Functions

// Hides all steps
function hideSteps () {
	for (let step of steps) {
		step.style.display = 'none';
	}
}

// Checks if all inputs in step 1 are filled
function allFilled () {
	let inputs = Array.from(stepOneInputs);
	let filled = inputs.every(element => element.value !== '');

	if (currentStepCount === 1) {
		if (filled) {
			next.classList.remove("dim-button");
			next.disabled = false;
		} else {
			next.classList.add("dim-button");
			next.disabled = true;
		}
	}
}

// Changes to previous step
function prevStep () {
	if (currentStepCount > 1) {
		stepButton.style.backgroundColor = "transparent";
		stepButton.style.color = "white";
		currentStep.style.display = "none";
		currentStep = document.querySelector(`.step-${--currentStepCount}`);
		currentStep.style.display = "flex";
		stepButton = document.getElementById(`button-${currentStepCount}`);
		stepButton.style.backgroundColor = "hsl(228, 100%, 84%)";
		stepButton.style.color = "hsl(213, 96%, 18%)";
	}
	back.style.display = currentStepCount > 1 ? "flex" : "none";
	next.textContent = currentStepCount === 4 ? "Confirm" : "Next Step";
}

// Perform necessary checks and navigate to next step
function nextStep () {
	if (currentStepCount < 5) {
		stepButton.style.backgroundColor = "transparent";
		stepButton.style.color = "white";
		currentStep.style.display = "none";
		currentStep = document.querySelector(`.step-${++currentStepCount}`);
		currentStep.style.display = "flex";
		stepButton = document.getElementById(`button-${currentStepCount <= 4 ? currentStepCount : 4}`);
		stepButton.style.backgroundColor = "hsl(228, 100%, 84%)";
		console.log(currentStepCount);
		stepButton.style.color = "hsl(213, 96%, 18%)";
		back.style.display = (currentStepCount < 2 || currentStepCount > 4) ? "none" : "flex";
		next.textContent = currentStepCount === 4 ? "Confirm" : "Next Step"
	}
	if (window.innerWidth < 768) {
		footer.style.display = (currentStepCount < 2 || currentStepCount > 4) ? "none" : "flex";
	} else {
		next.style.display = (currentStepCount < 2 || currentStepCount > 4) ? "none" : "flex";
	}

	// Disable next button in step 2 until a plan is chosen
	if (currentStepCount === 2) {
		planClicked();
	}

	// Disable next button in step 3 until addons are chosen
	if (currentStepCount === 3) {
		addOnClicked();
	}

	// Dynamically generate content for confirmation step
	if (currentStepCount === 4) {
		let selectedAddOns = Array.from(document.querySelectorAll('input[type="checkbox"][name="add-ons"]:checked + .card-text h3'));
		let addOnCost = Array.from(document.querySelectorAll('input[type="checkbox"][name="add-ons"]:checked + .card-text + .cost'));
		let addOns = document.querySelector(".step-4 .finishing .finishing-details");
		let plan = document.querySelector(".step-4 .finishing .plan h3");
		let selectedPlan = document.querySelector('input[name="plan"]:checked');
		let planCost = document.querySelector('input[name="plan"]:checked + .card-details .month-year');
		let toggle = document.getElementById("switch");
		let finishingCost = document.querySelector(".step-4 .finishing .finishing-cost");
		let total = document.querySelector('.step-4 .total');
		let totalCost = 0;
		let numberRegex = /\d+/;
		let match = planCost.textContent.match(numberRegex);
		
		totalCost += Number(match);

		selectedAddOns.forEach(element => console.log(element.innerHTML));
		addOnCost.forEach(element => console.log(element.innerHTML));

		plan.textContent = `${selectedPlan.value}(${toggle.checked ? 'Yearly' : 'Monthly'})`;
		finishingCost.textContent = planCost.textContent;
		addOns.innerHTML = '';
		
		for (let i = 0; i < selectedAddOns.length; i++) {
			let newP = document.createElement('p');
			let match = addOnCost[i].textContent.match(numberRegex);
			let number = match[0];

			totalCost += Number(number);
			newP.innerHTML = `${selectedAddOns[i].textContent} <span>${addOnCost[i].textContent}<span>`;
			addOns.appendChild(newP);
		}

		total.innerHTML = `<p>Total (${toggle.checked ? "Per Year" : "Per Month"})</p>
							<span>+\$${totalCost}/${toggle.checked ? "yr" : "mo"}</span>`;
	}
}

// Navigates back to step 2 to allow changes
function planChange () {
	stepButton.style.backgroundColor = "transparent";
	stepButton.style.color = "white";
	currentStepCount = 2;
	hideSteps();
	currentStep = document.querySelector(`.step-${currentStepCount}`);
	currentStep.style.display = "flex";
	stepButton = document.getElementById(`button-${currentStepCount}`);
	stepButton.style.backgroundColor = "hsl(228, 100%, 84%)";
	stepButton.style.color = "hsl(213, 96%, 18%)";
	next.textContent = currentStepCount === 4 ? "Confirm" : "Next Step";
}

// Ensures that an add-on is selected before next button is activated
function addOnClicked () {
	let addOns = Array.from(stepThreeInputs);
	let addOnsSelected = addOns.some(element => element.checked);
	if (currentStepCount === 3) {
		if (addOnsSelected) {
			next.classList.remove("dim-button");
			next.disabled = false;
		} else {
			next.classList.add("dim-button");
			next.disabled = true;
		}
	}
}

// Disables next button until a plan is chosen
function planClicked () {
	let plans = Array.from(stepTwoInputs);
	let planSelected = plans.some(element => element.checked);
	if (currentStepCount === 2) {
		if (planSelected) {
			next.classList.remove("dim-button");
			next.disabled = false;
			console.log("Freedom!");
		} else {
			next.classList.add("dim-button");
			next.disabled = true;
			console.log("None shall pass step 2!");
		}
	}
}
