const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("packs")
		.setDescription("Show a list of officials packs.")
		.setDMPermission(true),
	is_disabled: false,
	usage: "packs",

	async execute(interaction) {
		interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.blue)
				.setTitle("Officials packs list can found here: https://mei-a9.info/packs")
			],
			data: {
				type: 4,
			}
		}).catch(console.error);
	}
};