const router = require("express").Router();
const moment = require("moment");

const navs = require("../navs.json");
const mps = require("../data/mps.json");

function isMPIdValid(id) {
	if(isNaN(id)) return false;
	if(Number(id) <= 0) return false;
	if(Number(id) > mps.length) return false;
	if(!mps.find(mp => mp.id === id)) return false;

	return true;
};

router.get("/", (req, res) => {
	if(req.query.mp && isMPIdValid(req.query.mp)) {
		let mp = mps.find(m => m.id === req.query.mp);

		mp.duration = moment(mp.end, "DD/MM/YYYY").diff(moment(mp.start, "DD/MM/YYYY"), "days");

		res.status(200).render("mp", {
			title: "MEI - MP Season Details",
			mp: mp,
			navs: navs
		});
	} else {
		mps.forEach(mp => {
			mp.timestamp = moment(mp.start, "DD/MM/YYYY").unix();
		});

		res.status(200).render("mps", {
			title: "MEI - MPs Seasons",
			mps: mps.sort((a, b) => b.timestamp - a.timestamp),
			navs: navs
		});
	};
});

module.exports = router;