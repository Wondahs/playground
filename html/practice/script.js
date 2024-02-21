// Dynamically load CSS file
function loadCSS(filename) {
	var link = document.createElement('link');
	link.rel = 'stylesheet';
	link.type = 'text/css';
	link.href = filename;
	document.head.appendChild(link);
  }
  
  // Load different CSS files based on screen size
  window.onload = function() {
	if (window.innerWidth <= 768) {
	  loadCSS('./css/mobile.css');
	} else {
	  loadCSS('./css/pc.css');
	}
  };
  