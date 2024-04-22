let steps = Array.from(document.querySelectorAll('[class^="step-"]')).filter(element => /\d+/.test(element.className.split('-')[1]));

let next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next');
let back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back');
let currentStepCount = 1;
let currentStep = document.querySelector(`.step-${currentStepCount}`);
let footer = document.getElementById("footer");

back.style.display = "none";

window.addEventListener('resize', () => {
	console.log("Resized");
	next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next');
	back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back');
	footer.style.display = window.innerWidth < 768 && currentStepCount < 5 ?"flex" : "none";
	hideSteps();
	console.log(currentStepCount);
	currentStep = document.querySelector(`.step-${currentStepCount}`);
	currentStep.style.display = 'flex';

	back.style.display = currentStepCount > 1 ? "flex" : "none";
	next.addEventListener('click', nextStep);
	back.addEventListener('click', prevStep);
});

hideSteps();

function hideSteps () {
	for (let step of steps) {
		step.style.display = 'none';
	}
}

let stepButton = document.getElementById(`button-${currentStepCount}`);
stepButton.style.backgroundColor = "hsl(228, 100%, 84%)";
stepButton.style.color = "hsl(213, 96%, 18%)";

currentStep.style.display = 'flex';

next.addEventListener('click', nextStep);
back.addEventListener('click', prevStep);


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
	}
	back.style.display = (currentStepCount < 2 || currentStepCount > 4) ? "none" : "flex";
	if (window.innerWidth < 768) {
		footer.style.display = (currentStepCount < 2 || currentStepCount > 4) ? "none" : "flex";
	} else {
		next.style.display = (currentStepCount < 2 || currentStepCount > 4) ? "none" : "flex";
	}
}
