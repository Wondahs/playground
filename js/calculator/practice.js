const buttons = document.getElementById('numbers');

buttons.addEventListener('click', (event) => {
	if (event.target.tagName === 'BUTTON') {
		const buttonValue = event.target.textContent;

		if (buttonValue === '=') {
			calculate();
		} else if (buttonValue === 'C') {
			clear();
		} else {
			appendTo(buttonValue);
		}
	}
});

function appendTo(value) {
	let display = document.getElementById('display');

	display.textContent += value;
}
function clear() {
	let display = document.getElementById('display');
	let result = document.getElementById('result');

	display.textContent = '\u00A0';
	result.textContent = '\u00A0';
}

function calculate() {
	let display = document.getElementById('display');
	let result = document.getElementById('result');

	rslt = eval(display.textContent);
	calcResult = Math.round((rslt + Number.EPSILON) * 100) / 100;
	result.textContent = calcResult;
}
