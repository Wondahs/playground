let checkboxes = document.querySelectorAll('.step-3 input[type="checkbox"]');

function styleBorder () {
	let checkbox = this;
	let checkboxParent = checkbox.parentElement;

	checkboxParent.style.borderColor = checkbox.checked ? "blue" : "#ccc";
	checkboxParent.style.backgroundColor = checkbox.checked ? "#BFEFFF" : "white";

}

for (let checkbox of checkboxes) {
	checkbox.addEventListener('change', styleBorder);
}
