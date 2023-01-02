const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { get } = require("../cache");
const JsSearch = require("js-search");
const Table = require("table");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("location")
		.setDescription("Show tracks list of a location.")
		.setDMPermission(true)
		.addStringOption(option =>
			option.setName("location")
			.setRequired(true)
			.setAutocomplete(true)
			.setDescription("The name of the location")),
	is_disabled: false,
	usage: "location [location]",

	async execute(interaction) {
		let tracks = get("TRACKS");

		if(!tracks) {
			update("TRACKS");
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

		let track_details = tracks.filter(track => track.location.toUpperCase() == interaction.options.get("location").value.toString().toUpperCase());

		if(!track_details || track_details.length === 0) {
			return interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.red)
					.setTitle(`${config.EMOTES.error} None of the results match.`)
					.setDescription("Valid examples: cairo, shanghai")
				],
				data: {
					type: 4,
				}
			}).catch(console.error);
		};

		let list = [["LENGTH", "NAME"]];

		track_details.sort((a, b) => a.length - b.length).forEach(track => {
			list.push([track.length, track.track]);
		});

		interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setFooter({
					text: "Saw incorrect data? Tell us with /feedback"
				})
				.setColor("870C2C")
				.setTitle(`Tracks of ${interaction.options.get("location").value.toString().toUpperCase()}`)
				.setDescription(`\`\`\`c++
${Table.table(list, {
	border: Table.getBorderCharacters("void")
})}
\`\`\`
---------------------------------------------------------------------------`)
			],
			data: {
				type: 4,
			}
		}).catch(console.error);
	},

	async autocomplete(interaction) {
		let locations = [];

		let tracks = get("TRACKS");

		if(!tracks) {
			update("TRACKS");
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

		tracks.forEach(doc => {
			if(!locations.includes(doc.location.toUpperCase())) locations.push({
				name: doc.location.toUpperCase(),
				value: doc.location
			});
		});

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