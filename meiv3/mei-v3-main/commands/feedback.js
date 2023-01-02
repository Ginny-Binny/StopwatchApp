const fetch = require("node-fetch");
const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("feedback")
		.setDescription("Give us your feedback.")
		.setDMPermission(true)
		.addStringOption(option =>
			option.setName("message")
			.setDescription("The message you want to send")
			.setRequired(true)),
	is_disabled: false,
	usage: "feedback <message>",

	async execute(interaction) {
		fetch("https://discordapp.com/api/webhooks/752175380994981920/7RHpMdoStLdQrJ1KNnYKlE73V9DfeE1DLMO7vxoMJf3SM1ao2Pr8o-uQVF90BGcH0bwu", {
			method: "POST",
			body: JSON.stringify({
				content: `From: ${interaction.user.tag}
\`${interaction.options.getString("message")}\``
			}),
			headers: {"Content-Type": "application/json"}
		});

		interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.green)
				.setTitle(`${config.EMOTES.success} Message sent!`)
			],
			data: {
				type: 4,
			}
		}).catch(console.error);
	}
};