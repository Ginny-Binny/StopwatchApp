const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { get, update } = require("../cache");
const Humanize = require("humanize-plus");

const JsSearch = require("js-search");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("cost")
		.setDescription("Shows cost of a car.")
		.setDMPermission(true)
		.addStringOption(option =>
			option.setName("car")
			.setRequired(true)
			.setAutocomplete(true)
			.setDescription("The name of the car"))
		.addStringOption(option => 
			option.setName("level")
			.setRequired(false)
			.setDescription("The ⭐ level of the car")
			.addChoices(
				{
					name: "Stock",
					value: "stock"
				},
				{
					name: "1⭐",
					value: "1"
				},
				{
					name: "2⭐",
					value: "2"
				},
				{
					name: "3⭐",
					value: "3"
				},
				{
					name: "4⭐",
					value: "4"
				},
				{
					name: "5⭐",
					value: "5"
				},
				{
					name: "Max",
					value: "max"
				},
				{
					name: "Gold",
					value: "gold"
				}
			)),
	is_disabled: false,
	usage: "cost <car> [level]",

	async execute(interaction, car_id) {
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

		let CAR = cars.find(car => car.car_id.toString() === (typeof car_id === "string" ? car_id.toString() : interaction.options.get("car").value.toString()));

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
			.setFooter({
				text: `ID: ${CAR.car_id} - Saw incorrect data? Tell us with /feedback`
			})

		//------

		let upgrades = [];
		let upgrades_total = 0;

		CAR.upgrades_stages.forEach((stage, i) => {
			upgrades.push(`\`\`[${i + 1}]\`\`  **${Humanize.intComma(stage)}**`);
			upgrades_total += stage;
		});

		embed.addFields({
			name: "Upgrades Stages:",
			value: `${upgrades.join("\n")}

\`\`Stages Total:\`\` ${Humanize.intComma(upgrades_total)} x 4 = **${Humanize.intComma(upgrades_total * 4)}** ${config.EMOTES.credit}
${config.EMOTES.void}`
		}, {
			name: "Parts:",
			value: `\`\`Uncommons:\`\` ${CAR.parts.uncommons.per_stat * 4} x ${Humanize.intComma(CAR.parts.uncommons.cost_per_import)} = **${Humanize.intComma((CAR.parts.uncommons.per_stat * 4) * CAR.parts.uncommons.cost_per_import)}** ${config.EMOTES.credit}
\`\`Rares:\`\` ${CAR.parts.rares.per_stat * 4} x ${Humanize.intComma(CAR.parts.rares.cost_per_import)} = **${Humanize.intComma((CAR.parts.rares.per_stat * 4) * CAR.parts.rares.cost_per_import)}** ${config.EMOTES.credit}
${CAR.parts.epics.per_stat === 0 ? "" : `\`\`Epics:\`\` ${CAR.parts.epics.per_stat * 4} x ${Humanize.intComma(CAR.parts.epics.cost_per_import)} = **${Humanize.intComma((CAR.parts.epics.per_stat * 4) * CAR.parts.epics.cost_per_import)}** ${config.EMOTES.credit}`}
				
\`\`Parts Total:\`\` **${Humanize.intComma(((CAR.parts.uncommons.per_stat * 4) * CAR.parts.uncommons.cost_per_import) + ((CAR.parts.rares.per_stat * 4) * CAR.parts.rares.cost_per_import) + ((CAR.parts.epics.per_stat * 4) * CAR.parts.epics.cost_per_import))}** ${config.EMOTES.credit}
${config.EMOTES.void}`
		}, {
				name: "Total",
				value: `${Humanize.intComma(upgrades_total * 4)} + ${Humanize.intComma(((CAR.parts.uncommons.per_stat * 4) * CAR.parts.uncommons.cost_per_import) + ((CAR.parts.rares.per_stat * 4) * CAR.parts.rares.cost_per_import) + ((CAR.parts.epics.per_stat * 4) * CAR.parts.epics.cost_per_import))} = **${Humanize.intComma((upgrades_total * 4) + (((CAR.parts.uncommons.per_stat * 4) * CAR.parts.uncommons.cost_per_import) + ((CAR.parts.rares.per_stat * 4) * CAR.parts.rares.cost_per_import) + ((CAR.parts.epics.per_stat * 4) * CAR.parts.epics.cost_per_import)))}** ${config.EMOTES.credit}`
		});

		//-----

		interaction.editReply({
			ephemeral: false,
			embeds: [
				embed
			],
			data: {
				type: 4,
			}
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