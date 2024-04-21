let steps = document.querySelectorAll('[class^="step"]');

let next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next');
let back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back');


window.addEventListener('resize', () => {
	next = window.innerWidth < 768 ? document.querySelector('footer #next') : document.querySelector('.progress .next');
	back = window.innerWidth < 768 ? document.querySelector('footer #back') : document.querySelector('.progress .back');

	console.log("Resized")
	console.log(next ? next.textContent : "not found");
})
for (let step of steps) {
	step.style.display = 'none';
}

let currentStepCount = 1;
let currentStep = document.querySelector(`.step-${currentStepCount}`);

if (currentStepCount === 1) {
	console.log("Step 1")
	next.style.display = "none";
}

currentStep.style.display = 'flex';
