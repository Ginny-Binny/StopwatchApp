const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("invite")
		.setDescription("Shows bot's invite link.")
		.setDMPermission(true),
	is_disabled: false,
	usage: "invite",

	async execute(interaction) {
		interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.purple)
                .setTitle("Use this link to add MEI to any server.")
                .setDescription("__**[CLICK HERE](https://discord.com/api/oauth2/authorize?client_id=716647677370302465&permissions=448861109569&scope=bot%20applications.commands)**__")
			],
			data: {
				type: 4,
			}
		}).catch(console.error);
	}
};