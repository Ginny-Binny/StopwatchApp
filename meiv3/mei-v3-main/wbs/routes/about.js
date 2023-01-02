const router = require("express").Router();
const cache = require("../../cache");

const navs = require("../navs.json");

router.get("/", (req, res) => {
	let servers = [];

	cache.get("BOT").guilds.cache.forEach(guild => {
		servers.push({
			name: guild.name,
			members: guild.memberCount
		});
	});

	res.status(200).render("about", {
		title: "MEI - About Us",
		guilds: servers.sort((a, b) => b.members - a.members),
		navs: navs
	});
});

module.exports = router;