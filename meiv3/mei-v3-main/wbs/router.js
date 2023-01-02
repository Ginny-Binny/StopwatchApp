const navs = require("./navs.json");

module.exports = (app) => {
	app.use("/+", require("./routes/index"));

	app.use("/+timeline", require("./routes/timeline"));

	app.use("/+mps", require("./routes/mps"));

	app.use("/+about", require("./routes/about"));

	app.use("/+cars", require("./routes/cars"));

	app.use("/+tracks", require("./routes/tracks"));

	app.use("/+race", require("./routes/race"));

	app.use("/+beststarts", require("./routes/beststarts"));

	app.use("/+packs", require("./routes/packs"));

	app.use("/+article", require("./routes/article"));

	app.use("/+events", require("./routes/events"));

	app.use("/+games", require("./routes/games"));

	//app.use("/+compare", require("./routes/compare"));

	app.use((req, res) => {
		res.status(404).render("not_found", {
			title: "MEI - Not Found",
			navs: navs
		});
	});
};