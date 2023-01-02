const Table = require("table");
const moment = require("moment");
const config = require("../config.json");
const Events = require("../models/Events");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("events")
		.setDescription("Gives the amount of players in importants events.")
		.setDMPermission(true)
		.addStringOption(option =>
			option.setName("platform")
			.addChoices(
				{
					name: "WINDOWS",
					value: "windows"
				},
				{
					name: "IOS",
					value: "ios"
				},
				{
					name: "ANDROID",
					value: "android"
				}
			)
			.setDescription("The platform you want to check for")
			.setRequired(false)),
	is_disabled: false,
	usage: "events [platform]",

	async execute(interaction) {
		let platform = interaction.options.getString("platform");
		if(!platform) platform = "windows";

		Events.find({platform: interaction.options.getString("platform")}, (err, res) => {
			if(err) return console.log(err);

			if(!res) return interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.red)
					.setTitle(`${config.EMOTES.error} Nothing to clean.`)
				],
				data: {
					type: 4,
				}
			}).catch(console.error);

			let data = [
				["NAME", "TOTAL", "LAST UPDATE"]
			];

			res.forEach(event => {
				data.push([event.display_name, event.count, moment(event.updated_at).fromNow(false)]);
			});

			interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.blue)
					.setTitle(`Events for ${platform}`)
					.setFooter({
						text: `Refresh times may vary or getting delayed. Your help is welcome.`
					})
					.setDescription(`\`\`\`c++
${Table.table(data, {
	border: Table.getBorderCharacters("void"),
})}
\`\`\``)
				],
				data: {
					type: 4,
				}
			}).catch(console.error);
		});
	}
};