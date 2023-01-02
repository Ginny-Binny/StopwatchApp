const router = require("express").Router();
const fetch = require("node-fetch");

const streamers = require("../data/streamers.json");
const navs = require("../navs.json");

const Stats = require("../../models/Stats");
const News = require("../../models/News");
const moment = require("moment");
const cache = require("../../cache");

router.get("/", (req, res) => {
	let streams = [];
	let news = [[]];
	let stats = {};

	function cvc() {
		Stats.find({}, (ERR, STATS) => {
			stats = {
				total_requests: STATS.find(s => s.type === "total_requests").value,
				guilds: cache.get("BOT") ? cache.get("BOT").guilds.cache.size : "??"
			};

			let i = 0;
			
			News.find({}, (ERR, NEWS) => {
				NEWS.sort((a, b) => b.date - a.date).forEach(article => {
					if(i > 2) {
						news.push([{
							news_id: article.news_id,
							date: moment(article.date).format("DD/MM/YYYY"),
							title: article.title,
							image: article.image,
							description: article.description.split("\\n"),
							views: article.views,
							author: article.author
						}]);

						i = 0;
					} else {
						news[news.length - 1].push({
							news_id: article.news_id,
							date: moment(article.date).format("DD/MM/YYYY"),
							title: article.title,
							image: article.image,
							description: article.description.split("\\n"),
							views: article.views,
							author: article.author
						});
					};

					i++;
				});

				res.status(200).render("index", {
					title: "MEI - Home",
					news: news,
					streams: streams,
					stats: stats,
					navs: navs
				});
			});
		});
	};

	streamers.forEach((streamer, i) => {
		fetch(`https://www.youtube.com/channel/${streamer.id}`)
		.then(res => res.text())
		.then(text => {
			if(text.toString().search(`{"iconType":"LIVE"}`) !== -1) {
				streamer.isLive = true;
				streamer.viewers = text.toString().split(`"shortViewCountText":{"runs":[{"text":"`).pop().split(`"},`)[0];
			} else {
				streamer.isLive = false;
			};

			if(streamer.isLive) streams.push({
				name: streamer.name,
				url: `https://www.youtube.com/channel/${streamer.id}`,
				isLive: streamer.isLive,
				viewers: streamer.viewers || null
			});

			if((streamers.length - 1) === i) cvc();
		});
	});
});

module.exports = router;