let steps = Array.from(document.querySelectorAll('[class^="step-"]')).filter(element => /\d+/.test(element.className.split('-')[1]));

let next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next button');
let back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back button');
let currentStepCount = 1;
let currentStep = document.querySelector(`.step-${currentStepCount}`);
let footer = document.getElementById("footer");
let stepOneInputs = document.querySelectorAll('.step-1 input');
let stepTwoInputs = document.querySelectorAll('.step-2 input[name="plan"]');
let stepThreeInputs = document.querySelectorAll('.step-3 input')
let changePlan = document.getElementById("changePlan");

back.style.display = "none";
back.style.backgroundColor = "transparent";
back.style.color = "gray";
next.classList.add("dim-button");
next.disabled = true;

console.log(stepThreeInputs);

changePlan.addEventListener('click', planChange);

function planChange () {
	currentStepCount = 2;
	hideSteps();
	currentStep = document.querySelector(`.step-${currentStepCount}`);
	currentStep.style.display = "flex";
}

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
			console.log("None shall pass!");


		}
	}
}

window.addEventListener('resize', () => {
	console.log("Resized");
	next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next button');
	back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back button');
	footer.style.display = window.innerWidth < 768 && currentStepCount < 5 ?"flex" : "none";
	hideSteps();
	console.log(currentStepCount);
	next.addEventListener('click', nextStep);
	back.addEventListener('click', prevStep);
	currentStep = document.querySelector(`.step-${currentStepCount}`);
	currentStep.style.display = 'flex';
	allFilled();
	planClicked();

	back.style.display = currentStepCount > 1 ? "flex" : "none";
	back.style.backgroundColor = "transparent";
	back.style.color = "gray";
});

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

hideSteps();

let stepButton = document.getElementById(`button-${currentStepCount}`);
stepButton.style.backgroundColor = "hsl(228, 100%, 84%)";
stepButton.style.color = "hsl(213, 96%, 18%)";

currentStep.style.display = 'flex';

next.addEventListener('click', nextStep);
back.addEventListener('click', prevStep);

stepOneInputs.forEach(element => {
	element.addEventListener('input', allFilled);
});

stepTwoInputs.forEach(element => {
	element.addEventListener('change', planClicked);
});

stepThreeInputs.forEach(element => {
	element.addEventListener('change', addOnClicked);
});

function hideSteps () {
	for (let step of steps) {
		step.style.display = 'none';
	}
}

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

	if (currentStepCount === 2) {
		planClicked();
	}

	if (currentStepCount === 3) {
		let selectedPlan = document.querySelector('input[name="plan"]:checked');
		console.log("Selected plan is ", selectedPlan.value);
		addOnClicked();
	}

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
		console.log(total);

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
							<span>+\$${totalCost}/${toggle.checked ? "yr" : "mo"}</span>`

		console.log(totalCost);
	}
}
