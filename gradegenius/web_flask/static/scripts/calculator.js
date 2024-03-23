// $(document).ready(function() {
// 	const gradeSelect = $('#grade');
// 	const creditHoursSelect = $('#creditHours');
// 	const addCourseButton = $('#addCourse');
// 	const gpaForm = $('#gpaForm');
// 	const resultList = $('#result');
// 	const submitButton = $('#submit');
  
// 	let courseCount = 1; // Keep track of the number of courses
  
// 	addCourseButton.click(function() {
// 	  courseCount++;
  
// 	  // Create a new list item (li) element for the course
// 	  const newCourse = $('<li>').addClass('gpa_field').attr('id', `gpaForm-${courseCount}`);
  
// 	  // Clone the existing grade and credit hour select elements
// 	  const newGradeSelect = gradeSelect.clone(true).attr('id', `grade-${courseCount}`);
// 	  const newCreditHoursSelect = creditHoursSelect.clone(true).attr('id', `creditHours-${courseCount}`);
  
// 	  // Create input group elements for visual consistency
// 	  const newInputGroup1 = $('<div>').addClass('input-group');
// 	  const newInputGroup2 = $('<div>').addClass('input-group');
  
// 	  // Append the cloned selects and input groups to the new course element
// 	  newInputGroup1.append(newGradeSelect);
// 	  newInputGroup2.append(newCreditHoursSelect);
// 	  newCourse.append(newInputGroup1, newInputGroup2);
  
// 	  // Add a button to remove the course (optional)
// 	  const removeButton = $('<button>').text('Remove Course');
// 	  removeButton.click(function() {
// 		newCourse.remove();
// 		calculateGPA(); // Recalculate GPA after course removal
// 	  });
// 	  newCourse.append(removeButton);
  
// 	  // Insert the new course element before the submit button
// 	  newCourse.insertBefore(submitButton);
  
// 	  // Attach event listeners to the newly added grade and credit hour selects
// 	  newGradeSelect.change(calculateGPA);
// 	  newCreditHoursSelect.change(calculateGPA);
// 	});
  
// 	function calculateGPA() {
// 	  let totalQualityPoints = 0;
// 	  let totalCreditHours = 0;
  
// 	  // Loop through all course elements (including the original one)
// 	  const courseElements = gpaForm.find('.gpa_field');
// 	  courseElements.each(function() {
// 		const gradeSelect = $(this).find('#grade');
// 		const creditHoursSelect = $(this).find('#creditHours');
// 		const selectedGrade = gradeSelect.val();
// 		const selectedCreditHours = parseInt(creditHoursSelect.val());
  
// 		if (selectedGrade && selectedCreditHours) {
// 		  let gradePoints = 0;
// 		  switch (selectedGrade) {
// 			case 'A':
// 			  gradePoints = 4.0;
// 			  break;
// 			case 'B':
// 			  gradePoints = 3.0;
// 			  break;
// 			case 'C':
// 			  gradePoints = 2.0;
// 			  break;
// 			case 'D':
// 			  gradePoints = 1.0;
// 			  break;
// 			default:
// 			  gradePoints = 0.0;
// 		  }
  
// 		  totalQualityPoints += gradePoints * selectedCreditHours;
// 		  totalCreditHours += selectedCreditHours;
// 		}
// 	  });
  
// 	  let gpa;
// 	  if (totalCreditHours > 0) {
// 		gpa = totalQualityPoints / totalCreditHours;
// 		gpa = gpa.toFixed(2); // Round to two decimal places
// 	  } else {
// 		gpa = 'N/A (No courses entered)';
// 	  }
  
// 	  resultList.text(`Your calculated GPA is: ${gpa}`);
// 	}
  
// 	// Initial calculation (in case there are pre-filled values)
// 	calculateGPA();
//   });
  
//   submitButton.click(calculateGPA); // Calculate GPA on submit as well
  