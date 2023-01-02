const router = require("express").Router();
const navs = require("../navs.json");

const Cars = require("../../models/Cars");

router.get("/", (req, res) => {
	Cars.find({}, (ERR, CARS) => {
		if(!CARS || CARS.length === 0 || ERR) return res.status(500).render("error", {
			title: `MEI - ERROR 500`,
			error_message: "Internal Server Error",
			error_code: "500",
			navs: navs
		});

		let rk_cars = [];

		CARS.sort((a, b) => a.ranks.gold - b.ranks.gold).forEach(car => {
			rk_cars.push({
				name: `${car.brand} ${car.model}`.toUpperCase(),
				brand: car.brand,
				model: car.model,
				class: car.class,
				image: car.images[0],
				id: car.car_id
			});
		});

		res.status(200).render("compare", {
			title: "MEI - Comparing tool",
			cars: rk_cars,
			rows: {
				heads: [{
					id: "1",
					title: "LANCER"
				}]
			},
			navs: navs
		});
	});
});
module.exports = router;