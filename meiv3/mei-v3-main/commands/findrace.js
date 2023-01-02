const config = require("../config.json");
const { get, update } = require("../cache");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { MessageEmbed, MessageButton, MessageActionRow } = require("discord.js");

const JsSearch = require("js-search");

const emotes = {
	BRAND: "761985490563235900",
	MODEL: "761985491427524639",
	LOCATION: "761985490798510092",
	TRACK: "761985492408729600",
	MODE: "761985485551697951",
	EXEC: "739559462062391374"
};

module.exports = {
	data: new SlashCommandBuilder()
		.setName("findrace")
		.setDescription("Allow to search for career races, with filters.")
		.setDMPermission(true)
		.addStringOption(option => 
			option.setName("mode")
			.setRequired(false)
			.setDescription("Race mode")
			.addChoices(
				{
					name: "Classic (include 'Cops')",
					value: "CLASSIC"
				},
				{
					name: "Hunted",
					value: "HUNTED"
				},
				{
					name: "Time Attack",
					value: "TIMEATTACK"
				},
				{
					name: "Cops",
					value: "COPS"
				}
			))
		.addStringOption(option =>
			option.setName("location")
			.setRequired(false)
			.setAutocomplete(true)
			.setDescription("The name of the location")),
	is_disabled: true,
	usage: "findrace",

	async execute(interaction) {
		interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.blue)
				.setTitle("Pong!")
			],
			data: {
				type: 4,
			}
		}).catch(console.error);
	},
	async autocomplete(interaction) {
		let focusedOption = interaction.options.getFocused(true);
		let choices;

		if(focusedOption.name === "location") {
			let locations = [];

			get("TRACKS").forEach(doc => {
				if(!locations.includes(doc.location.toUpperCase())) locations.push({
					name: doc.location.toUpperCase(),
					value: doc.location
				});
			});

			choices = locations;
		};

		if(focusedOption.name === "") {
			choices = ['v9', 'v11', 'v12', 'v13', 'v14'];
		};

		let focusedValue = interaction.options.getFocused();
		let search = new JsSearch.Search("value");

		search.addIndex("name");
		search.addDocuments(locations);

		let filtered = search.search(focusedValue).slice(0, 5);

		await interaction.respond(filtered.map(choice => ({
			name: choice.name,
			value: choice.value
		})));
	}
};