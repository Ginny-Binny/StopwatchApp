const router = require("express").Router();

const navs = require("../navs.json");

const Packs = require("../../models/Packs");

router.get("/", (req, res) => {
	Packs.find({custom: false}, (ERR, RES) => {
		let packs = [];

		RES.forEach(pack => {
			packs.push({
				name: pack.display_name,
				id: pack.pack_id,
			});
		});

		res.status(200).render("packs", {
			title: "MEI - Packs List",
			navs: navs,
			packs: packs
		});
	});
});

module.exports = router;