let menuButton = document.getElementById("menu-button");
let navBar = document.getElementById("nav-bar");
let cartButton = document.getElementById("cart-icon");
let cartDiv = document.getElementById("cart");
let plusButton = document.getElementById("plus-button");
let minusButton = document.getElementById("minus-button");
let amount = document.getElementById("amount");
let itemCount = 0;

cartDiv.state = "closed";
amount.textContent = 0;

menuButton.addEventListener('click', () => {
	if (menuButton.state === "closed") {
		navBar.style.display = "flex";
		menuButton.src = "./images/icon-close.svg";
		menuButton.state = "opened";
	} else {
		navBar.style.display = "none";
		menuButton.src = "./images/icon-menu.svg";
		menuButton.state = "closed";
	}
	console.log("clicked me");
});

document.addEventListener('click', event => {
	if (event.target !== menuButton && !navBar.contains(event.target) && (window.innerWidth < 768)) {
		navBar.style.display = "none";
		menuButton.state = "closed";
		menuButton.src = "./images/icon-menu.svg";
	}
});

cartButton.addEventListener('click', () => {
	if (cartDiv.state === "closed") {
		cartDiv.style.display = "flex";
		cartDiv.state = "opened"
	} else {
		cartDiv.style.display = "none";
		cartDiv.state = "closed";
	}
});

document.addEventListener('click', event => {
	if (event.target !== cartButton && !cartDiv.contains(event.target)) {
		cartDiv.style.display = "none";
		cartDiv.state = "closed";
	}
});

plusButton.addEventListener('click', () => {
	amount.textContent = `${itemCount++}`;
	console.log("Plus 1");
});

minusButton.addEventListener('click', () => {
	if (itemCount > 0) {
		amount.textContent = `${--itemCount}`;
	}
});
