const router = require("express").Router();

const navs = require("../navs.json");
const cache = require("../../cache");

router.get("/", (req, res) => {
	let LB = [];

	cache.get("CARS").filter(c => c.start_accel && c.start_accel !== "").sort((a, b) => {
		return Number(a.start_accel.replace(":", "").replace(".", "")) - Number(b.start_accel.replace(":", "").replace(".", ""))
	}).forEach((car, i) => {
		LB.push({
			pos: i + 1,
			name: `${car.brand} ${car.model}`.toUpperCase(),
			time: `${car.start_accel.replace("00:0", "")}s`,
			stat: car.stats.gold.acceleration,
			car_id: car.car_id
		});
	});

	res.status(200).render("beststarts", {
		title: "MEI - 0-200km/h LB",
		navs: navs,
		lb: LB
	});
});

module.exports = router;