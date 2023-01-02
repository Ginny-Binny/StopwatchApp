const router = require("express").Router();
const navs = require("../navs.json");

const Events = require("../../models/Events");
const EventsHistory = require("../../models/EventsHistory");
const moment = require("moment");

router.get("/", (req, res) => {
	Events.find({}, (ERR, EVENTS) => {
		let events = [];

		EVENTS.forEach(event => {
			events.push({
				id: event.id,
				display_name: event.display_name,
				platform: event.platform,
				count: event.count,
				track_id: event.track_id,
				updated_at: moment(event.updated_at).format("DD/MM/YYYY HH:mm:ss"),
				updated_at_from_now: moment(event.updated_at).fromNow(),
				logs_hd: event.logs.map(a => moment(a.at).format("DD/MM/YYYY HH:mm:ss")),
				logs_vl: event.logs.map(a => a.value),
				tiers: event.tiers.split("/")
			});
		});

		res.status(200).render("events", {
			title: "MEI - Events",
			events: events,
			navs: navs
		});
	});
});

router.get("/:platform/:id", (req, res) => {
	if(req.params.platform && req.params.id) {
		Events.findOne({
			platform: req.params.platform.toLowerCase(),
			id: req.params.id.toLowerCase(),
		}, (ERR, EVENT) => {
			if(!EVENT) return res.status(404).render("not_found", {
				title: "MEI - Not Found",
				navs: navs
			});

			res.status(200).render("event", {
				title: `MEI - ${EVENT.display_name.toUpperCase()} on ${EVENT.platform}`,
				event: {
					id: EVENT.id,
					display_name: EVENT.display_name,
					platform: EVENT.platform,
					count: EVENT.count,
					track_id: EVENT.track_id,
					updated_at: moment(EVENT.updated_at).format("DD/MM/YYYY HH:mm:ss"),
					updated_at_from_now: moment(EVENT.updated_at).fromNow(),
					logs: EVENT.logs,
					logs_hd: EVENT.logs.map(a => moment(a.at).format("DD/MM/YYYY HH:mm:ss")),
					logs_vl: EVENT.logs.map(a => a.value),
					tiers: EVENT.tiers.split("/")
				},
				navs: navs
			});
		});
	} else {
		return res.status(404).render("not_found", {
			title: "MEI - Not Found",
			navs: navs
		});
	};
});

module.exports = router;