// Initialize variables
let addList = document.getElementById("add-list"); // Add-List Button.
let list = document.getElementById("gpa-list"); // ul element containing list of grade and credit hours.
let selectCount = 2; // Holds id number for select element.
let gradeCount = 2; // Holds id number for select element holding grade.
let hourCount = 2; // Holds id number for select element containing hour.
let grades = []; // Contains grades
let hours = []; // Contains hours
// sGradeIndex and sHourIndex are used to keep track of the index of a particular
// select element in the grades and hours array. This helps to prevent multiple values
// being added to the array whenever an option in the select element is picked multiple times
let sGradeIndex = 0;
let sHourIndex = 0;

// Get the first gpa field li element.
let listField = document.getElementById("gpa-field-1");

// Set custom attribute 'index'. Useful for keeping track of element position in array
// and rearranging when a li element is deleted.
listField.setAttribute('index', `${sGradeIndex}`);

// Get all select element in the li element and add event listeners.
let selectField = listField.querySelectorAll('select');

// Set custom attribute based on sGradeIndex. See explanation above.
selectField[0].setAttribute('grade-index', `${sGradeIndex++}`);

// The event listeners will store the selected option in the respective array
// Add event listener for grades.
selectField[0].addEventListener('change', (event) => {
    let selectedOption = event.target.value;
    let gradeIndex = event.target.getAttribute('grade-index');
    grades[gradeIndex] = selectedOption;
    console.log("Grades: ", grades);
    calculateGpa(grades, hours);
});

// Set custom attribute based on sHourIndex. See explanation above.
selectField[1].setAttribute('hour-index', `${sHourIndex++}`);
// Add event listener for hours.
selectField[1].addEventListener('change', (event) => {
    let selectedOption = event.target.value;
    let hourIndex = event.target.getAttribute('hour-index');
    hours[hourIndex] = selectedOption;
    console.log("Hours: ", hours);
    calculateGpa(grades, hours);
});

// Add event listener for Remove Grade button.
let removeButton = listField.querySelector('#remove-grade');

// let removeButton = removeButtons[0];
removeButton.addEventListener('click', (event) => {
	let liElement = event.target.closest('li');
    let liIndex = liElement.getAttribute('index');

    // Splice grades and hours array to remove value of select being deleted.
    grades.splice(liIndex, 1);
    hours.splice(liIndex, 1);
    liElement.remove();

    // Rearrange array and select index positions.
    rearrange();
    calculateGpa(grades, hours);
});

// Add event listener for the add list button.
addList.addEventListener('click', () => {
    // CLone the first li
    let listFieldClone = listField.cloneNode(true);

    // Set custom attribute based on sGradeIndex. See explanation above.
    listFieldClone.setAttribute('index', `${sGradeIndex}`);

    // Get all select elements and add event listeners same as above
    let selectClone = listFieldClone.querySelectorAll('select');

    // Change select id to avoid errors.
    selectClone[0].id = `gpa-grade-${gradeCount++}`;

    // Set custom attribute based on sGradeIndex. See explanation above.
    selectClone[0].setAttribute('grade-index', `${sGradeIndex++}`);

    // Add listener for grade.
    selectClone[0].addEventListener('change', (event) => {
        let selectedOption = event.target.value;
        let gradeIndex = event.target.getAttribute('grade-index');
        grades[gradeIndex] = selectedOption;
        console.log("Grades: ", grades);
        calculateGpa(grades, hours);
    });

    // Change select id to avoid errors.
    selectClone[1].id = `gpa-hour-${hourCount++}`;

    // Set custom attribute based on sHourIndex. See explanation above.
    selectClone[1].setAttribute('hour-index', `${sHourIndex++}`);

    // Add event listener for hour.
    selectClone[1].addEventListener('change', (event) => {
        let selectedOption = event.target.value;
        let hourIndex = event.target.getAttribute('hour-index');
        hours[hourIndex] = selectedOption;
        console.log("Hours: ", hours);
        calculateGpa(grades, hours);
    });

    // Add event listener for Remove Grade button.
    let removeButton = listFieldClone.querySelector('#remove-grade');
    // let removeButton = removeButtons[0];
    removeButton.addEventListener('click', (event) => {
	    let liElement = event.target.closest('li');
        let liIndex = liElement.getAttribute('index');

        // Splice grades and hours array to remove value of select being deleted.
        grades.splice(liIndex, 1);
        hours.splice(liIndex, 1);
	    liElement.remove();

        // Rearrange arrays
        rearrange();
        calculateGpa(grades, hours);
    });

    // Change li id to avoid errors.
    listFieldClone.id = `gpa-field-${selectCount++}`;

    // Append to parent ul element.
    list.appendChild(listFieldClone);
});

// GPA calculator
function calculateGpa(grades, hour) {
    let resultDiv = document.getElementById('result');
    if (grades.length === 0) {
        resultDiv.textContent = '\u00A0';
    }
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
	resultDiv.textContent = `GPA: ${gpa}`;
    } else {
	    resultDiv.textContent = '\u00A0';
    }
}

// Get calculate button and bind to GPA calculator
// let lastSelect = document.getElementById('calculate');
// lastSelect.addEventListener('click', () => {
// 	calculateGpa(grades, hours);
// });

// Rearrange positions of elements in arrays.
function rearrange() {
    sGradeIndex = 0;
    sHourIndex = 0;
    let gradeSelects = document.getElementsByClassName('gpa-grade');
    let hourSelects = document.getElementsByClassName('gpa-hour');
    let liElements = document.getElementsByTagName('li');

    for (i = 0; i < gradeSelects.length; i++) {
        console.log("Current index: ", i);
        gradeSelects[i].setAttribute('grade-index', `${i}`);
        hourSelects[i].setAttribute('hour-index', `${i}`);
        liElements[i].setAttribute('index', `${i}`);
    }
}
