const router = require("express").Router();

const navs = require("../navs.json");

const cache = require("../../cache");
const CryptoJS = require("crypto-js");

router.get("/", (req, res) => {
	let TRACKS = cache.get("TRACKS");

	if(!TRACKS) return res.status(500).render("error", {
		title: `MEI - ERROR 500`,
		error_message: "Internal Server Error",
		error_code: "500",
		navs: navs
	});

	function isTrackIdValid(id) {
		if(isNaN(id)) return false;
		if(Number(id) <= 0) return false;
		if(Number(id) > TRACKS.length) return false;
	
		return true;
	};

	if(req.query.track && isTrackIdValid(req.query.track)) {
		let TRACK = TRACKS.find(track => track.track_id == req.query.track);
		
		if(!TRACK) return res.status(500).render("error", {
			title: `MEI - ERROR 500`,
			error_message: "Internal Server Error",
			error_code: "500",
			navs: navs
		});

		let list = [];

		let CAREER = cache.get("CAREER");

		if(CAREER) {
			CAREER.forEach(chap => {
				chap.seasons.forEach(season => {
					season.races.forEach(race => {
						if(race.track_id == TRACK.track_id) {
							list.push({
								chap: chap.chapter.id,
								season: season.name,
								race: race.id,
								mode: race.mode,
								rank: race.rank,
								uid: encodeURIComponent(CryptoJS.AES.encrypt(`{"chap": ${chap.chapter.id},"season": "${season.name}","race": ${race.id},"cars": [${race.cars}]}`, "Hariix").toString())
							});
						};
					});
				});
			});
		};

		let WRS = cache.get("WRS");
		let RUNS;

		let LB = [];

		if(WRS) {
			RUNS = WRS.filter(wr => wr.track == TRACK.track_id);

			let pos = 1;
			let car;
	
			if(RUNS) {
				RUNS.sort((a, b) => Number(a.time.replace(":", "").replace(".", "")) - Number(b.time.replace(":", "").replace(".", ""))).forEach(wr => {
					car = cache.get("CARS").find(car => car.car_id == wr.car);
					if(!car) car = "??";
		
					LB.push({
						pos: pos,
						player: wr.player_name,
						channel: wr.player_channel,
						car: `${car.brand.toUpperCase()} - ${car.model.toUpperCase()}`,
						rank: wr.rank,
						time: wr.time,
						video: wr.video
					});
		
					pos++;
				});
			};
		};

		res.status(200).render("track", {
			title: `MEI - ${TRACK.track}`,
			track: {
				location: TRACK.location,
				name: TRACK.track,
				time: TRACK.length
			},
			lb: list,
			leaderboard: LB,
			navs: navs
		});
	} else {
		if(!TRACKS) return res.status(500).render("error", {
			title: `MEI - ERROR 500`,
			error_message: "Internal Server Error",
			error_code: "500",
			navs: navs
		});

		let data = [];

		TRACKS.forEach(track => {
			if(data.find(loc => loc.location === track.location)) {
				data[data.findIndex(loc => loc.location === track.location)].tracks.push({
					track: track.track,
					track_id: track.track_id
				});
			} else {
				data.push({
					location: track.location,
					tracks: [
						{
							track: track.track,
							track_id: track.track_id
						}
					]
				});
			};
		});

		let rows_data = [];
		let i = 0;

		data.forEach(loc => {
			if(rows_data.length === 0) {
				rows_data.push([
					{
						location: loc.location,
						tracks: loc.tracks
					}
				]);
			} else {
				if(i >= 5) {
					i = 0;
			
					rows_data.push([
						{
							location: loc.location,
							tracks: loc.tracks
						}
					]);
				} else {
					rows_data[rows_data.length - 1].push({
						location: loc.location,
						tracks: loc.tracks
					});
				};
			};

			i++;
		});

		res.status(200).render("tracks", {
			title: "MEI - Tracks list",
			rows_data: rows_data,
			navs: navs
		});
	};
});

module.exports = router;