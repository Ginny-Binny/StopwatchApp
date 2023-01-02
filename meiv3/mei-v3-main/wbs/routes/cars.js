const router = require("express").Router();
const Humanize = require("humanize-plus");

const navs = require("../navs.json");

const Cars = require("../../models/Cars");
const cache = require("../../cache");

const display_null_cards = false;

router.get("/", (req, res) => {
	let cars_list = cache.get("CARS");

	function isCarIdValid(id) {
		if(isNaN(id)) return false;
		if(Number(id) <= 0) return false;
		if(Number(id) > cars_list.length) return false;

		return true;
	};
	
	if(req.query.car && isCarIdValid(req.query.car)) {
		Cars.findOne({car_id: req.query.car}, (ERR, CAR) => {
			if(!CAR || ERR) return res.status(500).render("error", {
				title: `MEI - ERROR 500`,
				error_message: "Internal Server Error",
				error_code: "500",
				navs: navs
			});

			let bps = Object.values(CAR.blueprints).filter(e => e !== null);
			let bpsTotal = bps.filter(e => e !== "key").reduce((a, b) => a + b, 0);

			let stats_cards = [];

			let statsHeads = Object.keys(CAR.stats);
			let statsValues = Object.values(CAR.stats);
			let ranksValues = Object.values(CAR.ranks);

			let statRank;
			let statHeader;
			let statBp;
			let statCost;
			let no_footer = false;

			let COST = [];

			let t = 0;

			CAR.per_stars_upgrades.forEach(star => {
				Object.values(CAR.upgrades_stages).forEach((stage, index) => {
					if(index > star.stage_to_reach - 1) return;
					if(stage == null || stage == 0) return;
					t += Math.floor(stage * 4);
				});

				COST.push({
					stages: t,
					stage_to_reach: star.stage_to_reach,
					star: star.star,
					uncommon_cost: ((star.parts.uncommon.speed + star.parts.uncommon.accel + star.parts.uncommon.handl + star.parts.uncommon.nitro) != 0)
					?
					(((star.parts.uncommon.speed + star.parts.uncommon.accel + star.parts.uncommon.handl + star.parts.uncommon.nitro) * CAR.parts.uncommons.cost_per_import))
					:
					0,
					rare_cost: ((star.parts.rare.speed + star.parts.rare.accel + star.parts.rare.handl + star.parts.rare.nitro) != 0)
					?
					((star.parts.rare.speed + star.parts.rare.accel + star.parts.rare.handl + star.parts.rare.nitro) * CAR.parts.rares.cost_per_import)
					:
					0,
					epic_cost: ((star.parts.epic.speed + star.parts.epic.accel + star.parts.epic.handl + star.parts.epic.nitro) != 0)
					?
					((star.parts.epic.speed + star.parts.epic.accel + star.parts.epic.handl + star.parts.epic.nitro) * CAR.parts.epics.cost_per_import)
					:
					0,
					uncommon: [
						star.parts.uncommon.speed,
						star.parts.uncommon.accel,
						star.parts.uncommon.handl,
						star.parts.uncommon.nitro
					],
					rare: [
						star.parts.rare.speed,
						star.parts.rare.accel,
						star.parts.rare.handl,
						star.parts.rare.nitro
					],
					epic: [
						star.parts.epic.speed,
						star.parts.epic.accel,
						star.parts.epic.handl,
						star.parts.epic.nitro
					],
					total: t
						+
						((star.parts.uncommon.speed + star.parts.uncommon.accel + star.parts.uncommon.handl + star.parts.uncommon.nitro) * CAR.parts.uncommons.cost_per_import)
						+
						((star.parts.rare.speed + star.parts.rare.accel + star.parts.rare.handl + star.parts.rare.nitro) * CAR.parts.rares.cost_per_import)
						+
						((star.parts.epic.speed + star.parts.epic.accel + star.parts.epic.handl + star.parts.epic.nitro) * CAR.parts.epics.cost_per_import)
				});

				t = 0;
			});

			let upgrades = [];
			let upgrades_total = 0;
		
			CAR.upgrades_stages.forEach((stage, i) => {
				upgrades.push(`[${i + 1}] ${Humanize.intComma(stage)}`);
				upgrades_total += stage;
			});

			statsValues.forEach((card, index) => {
				if(!display_null_cards && (card.speed === null && card.acceleration === null && card.handling === null && card.nitro === null)) return;

				if(index === 0) {
					statHeader = "Stock";
					statRank = ranksValues[index] || "?";
					statBp = 0;
					statCost = 0;
					no_footer = true;
				} else {
					if(statsHeads[index] === "gold") {
						statHeader = "Gold";
						statRank = CAR.ranks.gold || "?";
						statBp = bpsTotal;
						statCost = Humanize.intComma(COST.find(item => item.star == index) ? COST.find(item => item.star == index).total : 0);
						no_footer = false;
					} else {
						statHeader = "⭐".repeat(index);
						statRank = ranksValues[index] || "?";
						statBp = bps.filter(e => e !== "key").slice(0, index).reduce((a, b) => a + b, 0);
						statCost = Humanize.intComma(COST.find(item => item.star == index) ? COST.find(item => item.star == index).total : 0);
						no_footer = false;
					};
				};

				stats_cards.push({
					title: `${statHeader} [${statRank || "?"}]`,
					speed: card.speed || "?",
					accel: card.acceleration || "?",
					handl: card.handling || "?",
					nitro: card.nitro || "?",
					bp: statBp,
					cost: statCost,
					no_footer: no_footer
				});
			});

			let start_accel_pos = cars_list.filter(c => (c.start_accel !== "" && c.start_accel !== null)).sort((a, b) => {
				return Number(a.start_accel.replace(":", "").replace(".", "")) - Number(b.start_accel.replace(":", "").replace(".", ""))
			});

			let final_data = {
				navs: navs,
				title: `MEI - ${CAR.brand} ${CAR.model}`.toUpperCase(),
				model: CAR.model.toUpperCase(),
				brand: CAR.brand.toUpperCase(),
				stars: "⭐".repeat(CAR.max_star),
				fuels: CAR.fuels,
				refills_in: CAR.refill,
				bps: `${bps.join("/")} (${bpsTotal})`,
				real_accel: (typeof CAR.start_accel === "string" && CAR.start_accel !== "") ? (CAR.start_accel.replace("00:0", "") || "?") : "?",
				start_accel_pos: start_accel_pos.findIndex(c => c.car_id === CAR.car_id) + 1,
				cclass: CAR.class,
				image: CAR.images[0],
				stats_cards: stats_cards,
				stages: upgrades,
				stages_total: Humanize.intComma(upgrades_total * 4),

				parts_total: Humanize.intComma(((CAR.parts.uncommons.per_stat * CAR.parts.uncommons.cost_per_import) * 4) + ((CAR.parts.rares.per_stat * CAR.parts.rares.cost_per_import) * 4) + ((CAR.parts.epics.per_stat * CAR.parts.epics.cost_per_import) * 4)),

				epics_total: Humanize.intComma((CAR.parts.epics.per_stat * CAR.parts.epics.cost_per_import) * 4),
				rares_total: Humanize.intComma((CAR.parts.rares.per_stat * CAR.parts.rares.cost_per_import) * 4),
				uncommons_total: Humanize.intComma((CAR.parts.uncommons.per_stat * CAR.parts.uncommons.cost_per_import) * 4),

				epics_per_stage: CAR.parts.epics.per_stat,
				rares_per_stage: CAR.parts.rares.per_stat,
				uncommons_per_stage: CAR.parts.uncommons.per_stat,

				uncommons_cost_per_import: CAR.parts.uncommons.cost_per_import,
				rares_cost_per_import: CAR.parts.rares.cost_per_import,
				epics_cost_per_import: CAR.parts.epics.cost_per_import,

				gold_cost: Humanize.intComma((upgrades_total * 4) + (((CAR.parts.uncommons.per_stat * 4) * CAR.parts.uncommons.cost_per_import) + ((CAR.parts.rares.per_stat * 4) * CAR.parts.rares.cost_per_import) + ((CAR.parts.epics.per_stat * 4) * CAR.parts.epics.cost_per_import))),
				parts_distribution: CAR.per_stars_upgrades,
				speeds: {
					yellow: CAR.nitro_speeds.yellow || "?",
					blue: CAR.nitro_speeds.blue || "?",
					orange: CAR.nitro_speeds.orange || "?",
					sw: CAR.nitro_speeds.orange || "?",
					drift: CAR.drift_speed || "?",
					air: CAR.air_speed || "?"
				},
				comments: CAR.comments.split("\\n"),
				specs: CAR.specs
			};
			
			res.status(200).render("car", final_data);
		});
	} else {
		Cars.find({}, (ERR, CARS) => {
			if(!CARS || CARS.length === 0 || ERR) return res.status(500).render("error", {
				title: `MEI - ERROR 500`,
				error_message: "Internal Server Error",
				error_code: "500",
				navs: navs
			});

			let rk_cars = [];

			CARS.sort((a, b) => a.ranks.gold - b.ranks.gold).forEach(car => {
				rk_cars.push({
					name: `${car.brand} ${car.model}`.toUpperCase(),
					brand: car.brand,
					model: car.model,
					class: car.class,
					image: car.images[0],
					id: car.car_id
				});
			});

			res.status(200).render("cars", {
				title: "MEI - Cars list",
				cars: rk_cars,
				navs: navs
			});
		});
	};
});

module.exports = router;