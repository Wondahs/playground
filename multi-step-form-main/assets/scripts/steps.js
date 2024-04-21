let steps = Array.from(document.querySelectorAll('[class^="step-"]')).filter(element => /\d+/.test(element.className.split('-')[1]));

let next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next');
let back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back');


window.addEventListener('resize', () => {
	next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next');
	back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back');

	console.log("Resized")
	console.log(next ? next.textContent : "not found");
});

function hideSteps () {
	for (let step of steps) {
		console.log(step.innerHtml);
		step.style.display = 'none';
	}
}

let currentStepCount = 1;
let currentStep = document.querySelector(`.step-${currentStepCount}`);

currentStep.style.display = 'flex';

next.addEventListener('click', nextStep);
back.addEventListener('click', prevStep);

function prevStep () {
	if (currentStepCount > 1) {
		currentStep.style.display = "none";
		currentStep = document.querySelector(`.step-${--currentStepCount}`);
		console.log(currentStepCount);
		currentStep.style.display = "flex";
	}
}

function nextStep () {
	if (currentStepCount < 5) {
		currentStep.style.display = "none";
		currentStep = document.querySelector(`.step-${++currentStepCount}`);
		console.log(currentStepCount);
		currentStep.style.display = "flex";
	}
}

