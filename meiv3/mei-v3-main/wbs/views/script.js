$(document).ready(() => {
	$(".modal-close").on("click touchstart", (e) => {
		$(".side-nav").toggleClass("open");
		e.preventDefault();
   	});
});