const router = require("express").Router();
const CryptoJS = require("crypto-js");
const cache = require("../../cache");

const navs = require("../navs.json");

router.get("/", (req, res) => {
	let CARS = cache.get("CARS");

	if(!CARS) return res.status(500).render("error", {
		title: `MEI - ERROR 500`,
		error_message: "Internal Server Error",
		error_code: "500",
		navs: navs
	});

	if(req.query.r) {
		let json = JSON.parse(CryptoJS.AES.decrypt(req.query.r, "Hariix").toString(CryptoJS.enc.Utf8));

		let cars = [];

		json.cars.forEach(id => {
			cars.push(CARS.find(car => car.car_id === id.toString()));
		});

		json.cars = cars;

		res.status(200).render("race", {
			title: `MEI - ${json.chap} - ${json.season} - ${json.race}`,
			data: json,
			navs: navs
		});
	} else {
		res.status(404).render("not_found", {
			title: "MEI - Not Found",
			navs: navs
		});
	};
});

module.exports = router;