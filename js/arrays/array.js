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
    displayResult(grades, hours);
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
        console.log(grades);
    });

    // Change select id to avoid errors.
    selectClone[1].id = `gpa-hour-${hourCount++}`;
    // Add event listener for hour.
    selectClone[1].addEventListener('change', (event) => {
        let selectedOption = event.target.value;
        hours += selectedOption;
        console.log(hours);

        displayResult(grades, hours);
    });

    // Change li id to avoid errors.
    listFieldClone.id = `gpa-field-${selectCount++}`;

    // Append to parent ul element.
    list.appendChild(listFieldClone);
});

function displayResult(grade, hour) {
    if (grade.length > 0 && grade.length === hour.length) {
        resultDiv.textContent = grade + hour;
    }
}

function calculateGpa(grades, hour) {
    if (grades.length > 0 && grades.length === hour.length) {

        let gradeNo = [];
        grades.forEach((grade, index) => {
            switch (grade) {
                case 'A':
                    gradeNo[index] = 5;
                    break;
                case 'B':
                    gradeNo[index] = 4;
                    break;
                case 'C':
                    gradeNo[index] = 3;
                    break;
                case 'D':
                    gradeNo[index] = 2;
                    break;
                case 'E':
                    gradeNo[index] = 1;
                    break;
                case 'F':
                    gradeNo[index] = 0;
                    break;
            } 
        });
    }
}