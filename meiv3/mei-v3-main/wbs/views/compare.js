let active_card;

function openCarSelec() {
	document.getElementById("popup_overlay").style.display = "block";
	document.getElementById("popup_overlay").style.display = "block";
	//$("#popup_overlay").toggle("show");
};


$(document).ready(() => {
	function updateDiff(active_card) {
		//find stats of main car
		let main_car_card = $(`#${active_card}`)[0].children[1].children[1].innerText;

		let m_car = {};

		m_car.id = active_card;

		main_car_card.split("\n").forEach(element => {
			if(element === "/" || element === "") return;

			if(element.startsWith("BPs: ")) {
				m_car.bps = element.replace("BPs: ", "");
			};

			if(element.startsWith("Cost: ")) {
				m_car.cost = element.replace("Cost: ", "");
				m_car.cost_str = element.replace("Cost: ", "").replace(",", "");
			};
		});

		//find others cards and update
		$(".card-text").each((i, item) => {
			let car = {};

			car.id = item.children[1].id.split(":")[1];

			//remove all data if head car

			if(m_car.id === car.id) {
				console.log(item.children);
			};

			item.innerText.split("\n").forEach(element => {
				if(element === "/" || element === "") return;
	
				if(element.startsWith("BPs: ")) {
					car.bps = element.replace("BPs: ", "");
				};
	
				if(element.startsWith("Cost: ")) {
					car.cost = element.replace("Cost: ", "");
					car.cost_str = element.replace("Cost: ", "").replace(",", "");
				};
			});

			//console.log(car);
		});
	};

	function addCar(id) {
		console.log(id);
	};

	$(".card").on("click touchstart", e => {
		let card = e.currentTarget;
		let bar = $(`#${card.id}`)[0].children[0];

		$(".car_bar").each((i, item) => {
			item.value = 0;
		});

		bar.value = 100;
		active_card = card.id;

		updateDiff(active_card);
   	});

	$("button.add_car").on("click touchstart", e => {
		$("#popup_overlay").toggle("show");
		$("#car_selc_popup").css("display", "block");
   	});

	$("#popup_overlay").on("click touchstart", e => {
		if(e.target.id !== "popup_overlay") return;

		$("#popup_overlay").toggle("show");
		$("#car_selc_popup").css("display", "none");
   	});

	$(".carline").on("click touchstart", e => {
		//if(e.target.id !== "carline") return;

		addCar(e);
   	});
});