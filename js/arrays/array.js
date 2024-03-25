let addList = document.getElementById("add-list");
let list = document.getElementById("gpa-list");

addList.addEventListener('click', () => {
    let listField = document.getElementById("gpa-field");
    let listFieldClone = listField.cloneNode(true);
    let selectClone = listFieldClone.querySelectorAll('select');
    
    selectClone.forEach((select) => {
        select.selectedIndex = 0;
    });

    list.appendChild(listFieldClone);
	addList.style.backgroundColor = blue;

});

function getRandomColor() {
    let letters = '0123456789ABCDEF';
    let color = '#';
    for (let i = 0; i < 6; i++) {
        color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}
