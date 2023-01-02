const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed } = require("discord.js");
const { get, update } = require("../cache");
const Humanize = require("humanize-plus");
const config = require("../config.json");
const short = require("short-number");

const JsSearch = require("js-search");
const MiniSearch = require("minisearch");

function diff(a, b) {
	let tmp = Math.abs(Number(a) - Number(b));

	if(!Number.isInteger(tmp)) tmp = tmp.toFixed(2);

	if(a > b) return `*-${tmp}*`;
	if(a == b) return "*=*";
	if(a < b) return `*+${tmp}*`;
};

module.exports = {
	data: new SlashCommandBuilder()
		.setName("compare")
		.setDescription("Compare two cars between them.")
		.setDMPermission(true)
		.addStringOption(option =>
			option.setName("car_1")
			.setRequired(true)
			.setDescription("The name of the 1st car"))
		/*.addStringOption(option =>
			option.setName("level_1")
			.setRequired(false)
			.setDescription("The ⭐ level of the 1st car")
			.addChoices([
				["Stock", "stock"],
				["1⭐", "1"],
				["2⭐", "2"],
				["3⭐", "3"],
				["4⭐", "4"],
				["5⭐", "5"],
				["Max", "max"],
				["Gold", "gold"]
			]))*/
			.addStringOption(option =>
				option.setName("car_2")
				.setRequired(true)
				.setDescription("The name of the 2nd car"))
			/*.addStringOption(option =>
				option.setName("level_2")
				.setRequired(false)
				.setDescription("The ⭐ level of the 2nd car")
				.addChoices([
					["Stock", "stock"],
					["1⭐", "1"],
					["2⭐", "2"],
					["3⭐", "3"],
					["4⭐", "4"],
					["5⭐", "5"],
					["Max", "max"],
					["Gold", "gold"]
				]))*/,
	is_disabled: false,
	usage: "compare <carName1> <carName2>",

	async execute(interaction) {
		let cars = get("CARS");

		if(!cars) {
			update("CARS");
			return interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.red)
					.setTitle(`${config.EMOTES.error} An error occured.`)
				],
				data: {
					type: 4
				}
			}).catch(console.error);
		};

		let CAR_A;
		let CAR_B;

		let searchTerm = interaction.options.getString("car_1");

		let firstEngine = new MiniSearch({
			fields: ["shortcuts", "brand", "model"],
			storeFields: ["car_id"],
			searchOptions: {
				fuzzy: 0.2
			}
		});

		cars.forEach(c => c.id = c.car_id);

		firstEngine.addAll(cars);

		let result = firstEngine.search(searchTerm)[0];

		let secondEngine = new JsSearch.Search("car_id");

		secondEngine.addIndex("shortcuts");
		secondEngine.addIndex("model");
		secondEngine.addIndex("brand");

		secondEngine.addDocuments(cars);

		//---

		if(!result) {
			result = secondEngine.search(searchTerm)[0];

			if(!result) return interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.red)
					.setTitle(`${config.EMOTES.error} None of the results match.`)
				],
				data: {
					type: 4
				}
			}).catch(console.error);
		};

		CAR_A = cars.find(car => car.car_id === result.car_id);

		if(!CAR_A) return interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.red)
				.setTitle(`${config.EMOTES.error} Sorry, an error occured.`)
			],
			data: {
				type: 4
			}
		}).catch(console.error);

		searchTerm = interaction.options.getString("car_2");

		result = firstEngine.search(searchTerm)[0];

		if(!result) {
			result = secondEngine.search(searchTerm)[0];
			
			if(!result) return interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.red)
					.setTitle(`${config.EMOTES.error} None of the results match.`)
				],
				data: {
					type: 4
				}
			}).catch(console.error);
		};

		CAR_B = cars.find(car => car.car_id === result.car_id);

		if(!CAR_B) return interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.red)
				.setTitle(`${config.EMOTES.error} Sorry, an error occured.`)
			],
			data: {
				type: 4
			}
		}).catch(console.error);

		let embed = new MessageEmbed()
		.setColor("FC034E")
		.setTitle(`${CAR_A.brand} ${CAR_A.model} / ${CAR_B.brand} ${CAR_B.model}`);

		let A_BP_TOTAL = Object.values(CAR_A.blueprints).filter(e => e !== null && e !== "key").reduce((a, b) => a + b, 0);
		let B_BP_TOTAL = Object.values(CAR_B.blueprints).filter(e => e !== null && e !== "key").reduce((a, b) => a + b, 0);

		let A_GOLD_COST = 0;

		CAR_A.upgrades_stages.forEach(stage => {
			A_GOLD_COST += stage * 4;
		});

		A_GOLD_COST += ((CAR_A.parts.uncommons.per_stat * 4) * CAR_A.parts.uncommons.cost_per_import);
		A_GOLD_COST += ((CAR_A.parts.rares.per_stat * 4) * CAR_A.parts.rares.cost_per_import);
		A_GOLD_COST += ((CAR_A.parts.epics.per_stat * 4) * CAR_A.parts.epics.cost_per_import);

		let B_GOLD_COST = 0;

		CAR_B.upgrades_stages.forEach(stage => {
			B_GOLD_COST += stage * 4;
		});

		B_GOLD_COST += ((CAR_B.parts.uncommons.per_stat * 4) * CAR_B.parts.uncommons.cost_per_import);
		B_GOLD_COST += ((CAR_B.parts.rares.per_stat * 4) * CAR_B.parts.rares.cost_per_import);
		B_GOLD_COST += ((CAR_B.parts.epics.per_stat * 4) * CAR_B.parts.epics.cost_per_import);

		let DIFF_GOLD_COST = short(Math.abs(A_GOLD_COST - B_GOLD_COST));

		if(A_GOLD_COST > B_GOLD_COST) DIFF_GOLD_COST = `*-${DIFF_GOLD_COST}*`;
		if(A_GOLD_COST == B_GOLD_COST) DIFF_GOLD_COST = "=";
		if(A_GOLD_COST < B_GOLD_COST) DIFF_GOLD_COST = `*+${DIFF_GOLD_COST}*`;

		embed.addFields({
			name: CAR_A.class,
			value: `<:bp:787052519217299506> **${Object.values(CAR_A.blueprints)[0] === "key" ? `🔑 + ${A_BP_TOTAL}` : A_BP_TOTAL}**
<:credit:740932705876967450> **${(A_GOLD_COST / 1000000).toFixed(1)}M**
<:0_:787056212722188420>`,
			inline: true
		}, {
			name: CAR_B.class,
			value: `**${Object.values(CAR_B.blueprints)[0] === "key" ? `🔑 + ${B_BP_TOTAL}` : B_BP_TOTAL}**
**${(B_GOLD_COST / 1000000).toFixed(1)}M**`,
			inline: true
		}, {
			name: "<:0_:787056212722188420>",
			value: `${diff(A_BP_TOTAL, B_BP_TOTAL)}
${DIFF_GOLD_COST}`,
			inline: true
		}, {
			name: `STOCK [${CAR_A.ranks[0]}]`,
			value: `<:speed:787049195403083836> **${CAR_A.stats[0].speed || "?"}km/h**
<:accel:787049189682708482> **${CAR_A.stats[0].acceleration || "?"}**
<:hand:787049191771078686> **${CAR_A.stats[0].handling || "?"}**
<:nitro:787049195143823370> **${CAR_A.stats[0].nitro || "?"}**
<:0_:787056212722188420>`,
			inline: true
		}, {
			name: `STOCK [${CAR_B.ranks[0]}]`,
			value: `**${CAR_B.stats[0].speed || "?"}km/h**
**${CAR_B.stats[0].acceleration || "?"}**
**${CAR_B.stats[0].handling || "?"}**
**${CAR_B.stats[0].nitro || "?"}**`,
			inline: true
		}, {
			name: "<:0_:787056212722188420>",
			value: `${diff(CAR_A.stats[0].speed, CAR_B.stats[0].speed)}
			${diff(CAR_A.stats[0].acceleration, CAR_B.stats[0].acceleration)}
			${diff(CAR_A.stats[0].handling, CAR_B.stats[0].handling)}
			${diff(CAR_A.stats[0].nitro, CAR_B.stats[0].nitro)}`,
			inline: true
		}, {
			name: `GOLD [${CAR_A.ranks.gold}]`,
			value: `<:speed:787049195403083836> **${CAR_A.stats.gold.speed || "?"}km/h**
<:accel:787049189682708482> **${CAR_A.stats.gold.acceleration || "?"}**
<:hand:787049191771078686> **${CAR_A.stats.gold.handling || "?"}**
<:nitro:787049195143823370> **${CAR_A.stats.gold.nitro || "?"}**

${CAR_A.nitro_speeds.blue > CAR_A.nitro_speeds.yellow ? "<:BlueFlame:757222895742091374>" : "<:YellowFlame:764500109362200586>"} **${CAR_A.nitro_speeds.blue}km/h**
<:tiresmoke:831228565319974934> **${CAR_A.start_accel.replace("00:0", "")}s**`,
			inline: true
		}, {
			name: `GOLD [${CAR_B.ranks.gold}]`,
			value: `**${CAR_B.stats.gold.speed || "?"}km/h**
**${CAR_B.stats.gold.acceleration || "?"}**
**${CAR_B.stats.gold.handling || "?"}**
**${CAR_B.stats.gold.nitro || "?"}**

**${CAR_B.nitro_speeds.blue || "?"}km/h**
**${CAR_B.start_accel.replace("00:0", "")}s**`,
			inline: true
		}, {
			name: "<:0_:787056212722188420>",
			value: `${diff(CAR_A.stats.gold.speed, CAR_B.stats.gold.speed)}
${diff(CAR_A.stats.gold.acceleration, CAR_B.stats.gold.acceleration)}
${diff(CAR_A.stats.gold.handling, CAR_B.stats.gold.handling)}
${diff(CAR_A.stats.gold.nitro, CAR_B.stats.gold.nitro)}
			
${diff(CAR_A.nitro_speeds.blue, CAR_B.nitro_speeds.blue)}`,
			inline: true
		});

		interaction.editReply({
			ephemeral: true,
			embeds: [
				embed
			],
			data: {
				type: 4
			}
		}).catch(console.error);
	}
};