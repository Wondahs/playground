let popup = document.getElementById("popup");
let left = document.querySelector(".left");

popup.innerHTML = `<img id="close-popup" src="./images/icon-close.svg" alt="">
<div id="left" class="left">${left.innerHTML}</div>`;

let popupThumbnails = document.querySelectorAll("#popup .left .thumbnails img")
let previewImg = document.querySelectorAll(".preview #preview-image");
let normalThumbnails = document.querySelectorAll("main .left .thumbnails img");
let closePopup = document.querySelector("#popup #close-popup");


closePopup.addEventListener('click', () => {
	popup.style.display = "none";
})

console.log(popupThumbnails);
console.log(previewImg);


thumbnailsPreview(popupThumbnails, previewImg[0]);
thumbnailsPreview(normalThumbnails, previewImg[1]);

function thumbnailsPreview (thumbnails, preview) {
	for (let i = 0; i < thumbnails.length; i++) {
		thumbnails[i].addEventListener('click', () => {
			preview.src = `./images/image-product-${i + 1}.jpg`;
			console.log(`Thumbnail ${i} clicked`);
		});
	}
}

previewImg[1].addEventListener('click', () => {
	popup.querySelector("#preview-image").src = this.src;
	popup.style.display = "flex";
})
