let menuButton = document.getElementById("menu-button");
let navBar = document.getElementById("nav-bar");


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

