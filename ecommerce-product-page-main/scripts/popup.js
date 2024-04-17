let previewImg = document.querySelectorAll(".preview #preview-image");
let normalThumbnails = document.querySelectorAll("main .left .thumbnails img");

thumbnailsPreview(normalThumbnails, previewImg[0]);

previewImg[0].addEventListener('click', (event) => {

	if (window.innerWidth > 768) {
		popup = document.getElementById("popup");
		left = document.querySelector(".left");

		popup.style.display = "none";
		popup.innerHTML = `<img id="close-popup" src="./images/icon-close.svg" alt=""><div id="left" class="left">${left.innerHTML}</div>`;
		popup.querySelector("#preview-image").src = event.target.src;

		let popupPreview = popup.querySelector("#preview-image");
		let popupThumbnails = popup.querySelectorAll(".left .thumbnails img");
		let closePopup = document.querySelector("#popup #close-popup");
		let popupLeft = popup.querySelector(".left");

		closePopup.addEventListener('click', () => {
			popup.style.display = "none";
			popup.innerHTML = "";
		});

		thumbnailsPreview(popupThumbnails, popupPreview);
		popup.style.display = "flex";
		popupLeft.style.zIndex = 90;

		popup.addEventListener('click', event => {
			popClose(event, popupLeft);
		});
	}
});

function popClose (event, popupLeft) {
	console.log(event.target);
	if (popup.style.display === "flex" && !popupLeft.contains(event.target)) {
		popup.style.display = "none";
		popup.innerHTML = "";
	}
}

function thumbnailsPreview (thumbnails, preview) {
	for (let i = 0; i < thumbnails.length; i++) {
		thumbnails[i].addEventListener('click', () => {
			preview.src = `./images/image-product-${i + 1}.jpg`;
			console.log(`Thumbnail ${i} clicked`);
		});
	}
}
