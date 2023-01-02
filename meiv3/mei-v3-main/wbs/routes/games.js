const router = require("express").Router();
const navs = require("../navs.json");

router.get("/", (req, res) => {
	res.status(200).render("games", {
		title: "MEI - Games",
		navs: navs
	});
});

router.get("/guessthecar/:level", (req, res) => {
	if(["easy", "normal", "hard", "xtrem"].includes(req.params.level.toLowerCase())) {
		let level = req.params.level.toUpperCase();
		let questions = [];

		questions.push({
			img: ""
		});

		res.status(200).render("guessthecar", {
			title: "MEI - Guess the car",
			questions: questions,
			level: level,
			navs: navs
		});
	} else {
		return res.status(404).render("not_found", {
			title: "MEI - Not Found",
			navs: navs
		});
	};
});

module.exports = router;