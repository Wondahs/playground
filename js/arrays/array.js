// Initialize variables
let addList = document.getElementById("add-list"); // Add-List Button.
let list = document.getElementById("gpa-list"); // ul element containing list of grade and credit hours.
let selectCount = 2; // Holds id number for select element.
let gradeCount = 2; // Holds id number for select element holding grade.
let hourCount = 2; // Holds id number for select element containing hour.
let grades = []; // Contains grades
let hours = []; // Contains hours
let resultDiv = document.getElementById('result');

// Get the first gpa field li element.
let listField = document.getElementById("gpa-field-1");
// Get all select element in the li element and add event listeners.
let selectField = listField.querySelectorAll('select');
// The event listeners will store the selected option in the respective array

// Add event listener for grades.
selectField[0].addEventListener('change', (event) => {
    let selectedOption = event.target.value;
    grades += selectedOption;
    console.log(grades);
});
// Add event listener for hours.
selectField[1].addEventListener('change', (event) => {
    let selectedOption = event.target.value;
    hours += selectedOption;
    console.log(hours);
});

// Add event listener for Remove Grade button.
let removeButtons = listField.querySelectorAll('button');
let removeButton = removeButtons[0];
removeButton.addEventListener('click', (event) => {
	let liElement = event.target.closest('.gpa-field');
	liElement.remove();
});

// Add event listener for the add list button.
addList.addEventListener('click', () => {
    // CLone the first li
    let listFieldClone = listField.cloneNode(true);

    // Get all select elements and add event listeners same as above
    let selectClone = listFieldClone.querySelectorAll('select');

    // Change select id to avoid errors.
    selectClone[0].id = `gpa-grade-${gradeCount++}`;

    // Add listener for grade.
    selectClone[0].addEventListener('change', (event) => {
        let selectedOption = event.target.value;
        grades += selectedOption;
    });

    // Change select id to avoid errors.
    selectClone[1].id = `gpa-hour-${hourCount++}`;
    // Add event listener for hour.
    selectClone[1].addEventListener('change', (event) => {
        let selectedOption = event.target.value;
        hours += selectedOption;
    });

    // Add event listener for Remove Grade button.
    let removeButtons = listFieldClone.querySelectorAll('button');
    let removeButton = removeButtons[0];
    removeButton.addEventListener('click', (event) => {
	    let liElement = event.target.closest('.gpa-field');
	    liElement.remove();
});

    // Change li id to avoid errors.
    listFieldClone.id = `gpa-field-${selectCount++}`;

    // Append to parent ul element.
    list.appendChild(listFieldClone);
});

// GPA calculator
function calculateGpa(grades, hour) {
    // Calculate only if grades and hour arrays have same length.
    if (grades.length > 0 && grades.length === hour.length) {
	let gradeNo = 0; // GPA grade converted to number using the 5-point GPA scale
	let gpa = 0;
	let qualityPoints = 0;
	let total = 0; // Total credit hours
        for (index = 0; index < grades.length; index++) {
	    // Convert grade to its corresponding numerical weight.
            switch (grades[index]) {
                case 'A':
                    gradeNo = 5;
                    break;
                case 'B':
                    gradeNo = 4;
                    break;
                case 'C':
                    gradeNo = 3;
                    break;
                case 'D':
                    gradeNo = 2;
                    break;
                case 'E':
                    gradeNo = 1;
                    break;
                case 'F':
                    gradeNo = 0;
                    break;
            }
	    // Convert hour to integer
	    hourDigit = Number(hour[index]);
	    total += hourDigit;
	    qualityPoints += gradeNo * hourDigit;
	}
	gpa = total !== 0 ?  qualityPoints / total : 0;
	gpa = gpa.toFixed(2);
	resultDiv.textContent = `Your GPA is ${gpa}`;
    } else {
	    resultDiv.textContent = "Select a Grade";
    }
}

// Get calculate button and bind to GPA calculator
let lastSelect = document.getElementById('calculate');

lastSelect.addEventListener('click', () => {
	calculateGpa(grades, hours);
});
