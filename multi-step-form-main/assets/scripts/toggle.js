let toggle = document.getElementById("switch");
let proPrice = document.getElementById("pro-bill");
let arcadePrice = document.getElementById("arcade-bill");
let advancedPrice = document.getElementById("advanced-bill");
let yearly = document.getElementById("yearly");
let monthly = document.getElementById("monthly");
let bonus = document.getElementsByClassName("bonus");
let online = document.getElementById("cost-online-service");
let storage = document.getElementById("cost-storage");
let customize = document.getElementById("cost-customize");

monthly.style.fontWeight = "bold";
yearly.style.fontWeight = "normal";

toggle.addEventListener('change', monthYear);

function monthYear () {
	yearly.style.fontWeight = toggle.checked ? "bold" : "normal";
	monthly.style.fontWeight = toggle.checked ? "normal" : "bold";

	arcadePrice.innerHTML = toggle.checked ? "$90/yr" : "$9/mo";
	advancedPrice.innerHTML = toggle.checked ? "$120/yr" :
 "$12/mo";
	proPrice.innerHTML = toggle.checked ? "$150/yr" :
 "$15/mo";
	Array.from(bonus).forEach(element => element.style.display = toggle.checked ? "inline" : "none");
	online.innerHTML = toggle.checked ? "$10/yr" : "$1/mo";
	storage.innerHTML = toggle.checked ? "$20/yr" : "$2/mo";
	customize.innerHTML = toggle.checked ? "$20/yr" : "$2/mo";
	planClicked();
}
