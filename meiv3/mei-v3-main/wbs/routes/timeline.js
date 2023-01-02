const router = require("express").Router();
const moment = require("moment");

const navs = require("../navs.json");
const events_timeline = require("../data/timeline.json");

router.get("/", (req, res) => {
	events_timeline.forEach(event => {
		event.timestamp = moment(event.start, "DD/MM/YYYY").unix();
	});

	res.status(200).render("timeline", {
		title: "MEI - Timeline",
		timeline: events_timeline.sort((a, b) => b.timestamp - a.timestamp),
		navs: navs
	});
});

module.exports = router;