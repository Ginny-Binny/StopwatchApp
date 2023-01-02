const config = require("../config.json");
const { MessageEmbed, MessageButton, MessageActionRow } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { get, update } = require("../cache");

const JsSearch = require("js-search");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("car")
		.setDescription("Shows stats of a car.")
		.setDMPermission(true)
		.addStringOption(option =>
			option.setName("car")
			.setRequired(true)
			.setAutocomplete(true)
			.setDescription("The name of the car"))
		/*.addStringOption(option => 
			option.setName("level")
			.setRequired(false)
			.setDescription("The ⭐ level of the car")
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
	usage: "car <car> [level]",

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

		let CAR = cars.find(car => car.car_id.toString() === interaction.options.get("car").value.toString());

		if(!CAR) {
			return interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.red)
					.setTitle(`${config.EMOTES.error} None of the results match.`)
					.setDescription("Valid examples: lancer, jesko")
				],
				data: {
					type: 4,
				}
			}).catch(console.error);
		};

		//if(levelTerm !== null) {};

		let classIcon;
	
		switch(CAR.class) {
			case "D":
				classIcon = "https://i.imgur.com/DkoLmUF.png";
			break;

			case "C":
				classIcon = "https://i.imgur.com/f3f2Rje.png";
			break;

			case "B":
				classIcon = "https://i.imgur.com/JgNy3B0.png";
			break;

			case "A":
				classIcon = "https://i.imgur.com/oB0jXjq.png";
			break;

			case "S":
				classIcon = "https://i.imgur.com/Q1jeg3Q.png";
			break;
		};

		let color;

		switch(CAR.rarity) {
			case "Uncommon":
				color = config.COLORS.uncommon_bp;
			break;

			case "Rare":
				color = config.COLORS.rare_bp;
			break;

			case "Epic":
				color = config.COLORS.epic_bp;
			break;
		};

		let bps = Object.values(CAR.blueprints).filter(e => e !== null && e !== "key");
		let bpsTotal = bps.reduce((a, b) => a + b, 0);

		//------

		let embed = new MessageEmbed()
		.setColor(color)
		.setAuthor({
			name: `${CAR.brand} ${CAR.model}`.toUpperCase(),
			iconURL: classIcon,
			url: `https://www.mei-a9.info/cars?car=${CAR.car_id}`
		})
		.setImage(CAR.images[0])
		.setTitle("⭐".repeat(CAR.max_star))
		.setDescription(`${config.EMOTES.bp} **${Object.values(CAR.blueprints)[0] === "key" ? "🔑/" : ""}${bps.join("/")} || ${Object.values(CAR.blueprints)[0] === "key" ? `🔑 + ${bpsTotal}` : bpsTotal}**
${config.EMOTES.fuel} **${CAR.fuels} fuels** - **${CAR.refill}**`)
		.setFooter({
			text: `ID: ${CAR.car_id} - Saw incorrect data? Tell us with /feedback`
		})

		//------

		let statsHeads = Object.keys(CAR.stats);
		let statsValues = Object.values(CAR.stats);
		let ranksValues = Object.values(CAR.ranks);

		let statRank;
		let statHeader;

		statsValues.forEach((card, index) => {
			if(card.speed === null && card.acceleration === null && card.handling === null && card.nitro === null) return;

			if(index === 0) {
				statHeader = "Stock";
				statRank = ranksValues[index] || "?";
			} else {
				if(statsHeads[index] === "gold") {
					statHeader = "Gold";
					statRank = CAR.ranks.gold || "?";
				} else {
					statHeader = "⭐".repeat(index);
					statRank = ranksValues[index] || "?";
				};
			};

			embed.addFields({
				name: `${statHeader} [${statRank || "?"}]`,
				value: `${config.EMOTES.speed} **${card.speed || "?"}km/h**
${config.EMOTES.acceleration} **${card.acceleration || "?"}**
${config.EMOTES.handling} **${card.handling || "?"}**
${config.EMOTES.nitro} **${card.nitro || "?"}**`,
				inline: true
			});
		});

		let start_accel_pos = cars.filter(c => (c.start_accel !== "" && c.start_accel !== null)).sort((a, b) => {
			return Number(a.start_accel.replace(":", "").replace(".", "")) - Number(b.start_accel.replace(":", "").replace(".", ""))
		});

		embed.addFields({
			name: config.EMOTES.void,
			value: `**0-200km/h:** ${(typeof CAR.start_accel === "string" && CAR.start_accel !== "") ? `${CAR.start_accel.replace("00:0", "")}s *(#${start_accel_pos.findIndex(c => c.car_id === CAR.car_id) + 1})*` : "?"}
**Air:** ${CAR.air_speed || "?"}km/h
${CAR.nitro_speeds.blue === CAR.nitro_speeds.yellow ? `${config.EMOTES.YellowFlame} ${CAR.nitro_speeds.yellow || "?"}km/h` : (CAR.nitro_speeds.yellow === CAR.nitro_speeds.shockwave && CAR.nitro_speeds.yellow === CAR.nitro_speeds.orange) ? `${config.EMOTES.YellowFlame}${config.EMOTES.PurpleFlame}${config.EMOTES.OrangeFlame} ${CAR.nitro_speeds.yellow || "?"}km/h
${config.EMOTES.BlueFlame} ${CAR.nitro_speeds.blue || "?"}km/h` : `${config.EMOTES.YellowFlame} ${CAR.nitro_speeds.yellow || "?"}km/h
${config.EMOTES.BlueFlame} ${CAR.nitro_speeds.blue || "?"}km/h
${config.EMOTES.OrangeFlame} ${CAR.nitro_speeds.orange || "?"}km/h
${config.EMOTES.PurpleFlame} ${CAR.nitro_speeds.shockwave || "?"}km/h`}`
		});

		//-----

		interaction.editReply({
			ephemeral: false,
			embeds: [
				embed
			],
			data: {
				type: 4,
			},
			components: [
				new MessageActionRow()
					.addComponents(
						new MessageButton()
							.setCustomId("upgrades")
							.setLabel("Upgrades")
							.setStyle("SUCCESS"),
						new MessageButton()
							.setCustomId("compare")
							.setLabel("Compare")
							.setStyle("PRIMARY")
							.setDisabled(true),
						new MessageButton()
							.setURL(`https://www.mei-a9.info/cars?car=${CAR.car_id}`)
							.setLabel("Website")
							.setStyle("LINK")
					)
			]
		}).then(PANEL => {
			let UPGRADES_DISABLED = false;
			let COMPARE_DISABLED = true;

			PANEL.awaitMessageComponent({
				filter: (i => i.customId === "upgrades" && !i.user.bot),
				time: 300000,
				componentType: "BUTTON"
			}).then(i => {
				i.deferReply().then(() => {
					require("./cost").execute(i, CAR.car_id);

					UPGRADES_DISABLED = true;

					interaction.editReply({
						ephemeral: false,
						embeds: [
							embed
						],
						data: {
							type: 4,
						},
						components: [
							new MessageActionRow()
								.addComponents(
									new MessageButton()
										.setCustomId("upgrades")
										.setLabel("Upgrades")
										.setStyle("SUCCESS")
										.setDisabled(UPGRADES_DISABLED),
									new MessageButton()
										.setCustomId("compare")
										.setLabel("Compare")
										.setStyle("PRIMARY")
										.setDisabled(COMPARE_DISABLED),
									new MessageButton()
										.setURL(`https://www.mei-a9.info/cars?car=${CAR.car_id}`)
										.setLabel("Website")
										.setStyle("LINK")
								)
						]
					});
				}).catch(console.error);
			}).catch(console.error);

			//-----

			PANEL.awaitMessageComponent({
				filter: (i => i.customId === "compare" && !i.user.bot),
				time: 300000,
				componentType: "BUTTON"
			}).then(i => {
				i.deferReply().then(() => {
					i.editReply("no").catch(console.error);

					COMPARE_DISABLED = true;

					interaction.editReply({
						ephemeral: false,
						embeds: [
							embed
						],
						data: {
							type: 4,
						},
						components: [
							new MessageActionRow()
								.addComponents(
									new MessageButton()
										.setCustomId("upgrades")
										.setLabel("Upgrades")
										.setStyle("SUCCESS")
										.setDisabled(UPGRADES_DISABLED),
									new MessageButton()
										.setCustomId("compare")
										.setLabel("Compare")
										.setStyle("PRIMARY")
										.setDisabled(COMPARE_DISABLED),
									new MessageButton()
										.setURL(`https://www.mei-a9.info/cars?car=${CAR.car_id}`)
										.setLabel("Website")
										.setStyle("LINK")
								)
						]
					});
				}).catch(console.error);
			}).catch(console.error);
		}).catch(console.error);
	},
	async autocomplete(interaction) {
		let cars = get("CARS");

		if(!cars) {
			update("CARS");
			throw "No cache";
		};

		let focusedValue = interaction.options.getFocused();
		let search = new JsSearch.Search("car_id");

		search.addIndex("brand");
		search.addIndex("model");
		search.addDocuments(cars);

		let filtered = search.search(focusedValue).slice(0, 10);

		await interaction.respond(filtered.map(choice => ({
			name: `${choice.brand} ${choice.model}`.toUpperCase(),
			value: choice.car_id.toString()
		})));
	}
};