let menuButton = document.getElementById("menu-button");
let navBar = document.getElementById("nav-bar");
let cartButton = document.getElementById("cart-icon");
let cartDiv = document.getElementById("cart");
let plusButton = document.getElementById("plus-button");
let minusButton = document.getElementById("minus-button");
let amount = document.getElementById("amount");
let itemNo = document.getElementById("item-no");
let itemCount = 0;
let addToCart = document.getElementById("add-to-cart");
let itemPrice = document.getElementById("item-price");
let deleteButton = document.getElementById("delete-button");
let preview = document.getElementById("preview-image");
let nextButton = document.getElementById("next");
let prevButton = document.getElementById("prev");
let previewIndex = 1;

preview.src = "./images/image-product-1.jpg";
cartDiv.state = "closed";
amount.textContent = 0;
itemNo.textContent = '';
itemNo.style.display = 'none';

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
	amount.textContent = `${++itemCount}`;
	console.log("Plus 1");
});

minusButton.addEventListener('click', () => {
	if (itemCount > 0) {
		amount.textContent = `${--itemCount}`;
	}
});

addToCart.addEventListener('click', () => {
	if (itemCount === 0) {
		itemNo.style.display = 'none';
		emptyCart();
	} else {
		emptyCart(1);
		itemNo.style.display = 'block';
		itemNo.textContent = `${itemCount}`;
		itemPrice.innerHTML = `\$125.00 x ${itemCount} <b>\$${(125.00 * itemCount).toFixed(2)}</b>`;
	}
});

deleteButton.addEventListener('click', emptyCart);


function emptyCart (state=0) {
	let items = cartDiv.querySelectorAll(".items");
	let checkoutButton = cartDiv.querySelector("#checkout");
	let empty = cartDiv.querySelector("#empty-cart");

	for (const item of items) {
		item.style.display = state === 1 ? "flex" : "none";
	}
	checkoutButton.style.display = state === 1 ? "block" : "none";
	empty.style.display = state === 1 ? "none" : "block";
	itemNo.style.display = state === 1 ? "block" : "none";
}

nextButton.addEventListener('click', () => {

	preview.src = `./images/image-product-${previewIndex <= 3 ? ++previewIndex : 4}.jpg`;
	console.log(previewIndex);
});

prevButton.addEventListener('click', () => {
	preview.src = `./images/image-product-${previewIndex >= 2 ? --previewIndex : 1}.jpg`;
	console.log(previewIndex);
});
