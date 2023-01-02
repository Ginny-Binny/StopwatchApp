const { MessageEmbed, MessageButton, MessageActionRow } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const Chance = require("chance");
const { get, update } = require("../cache");
const config = require("../config.json");

const chance = new Chance();

let latest = [];

function rng(max) {
	let i = 0;
	let tmp = chance.natural({
		min: 1,
		max: max
	});

	while(latest.includes(tmp) && i < 1000) {
		tmp = chance.natural({
			min: 1,
			max: max
		});
		i++;
	};

	if(latest.length >= 20) latest.shift();

	latest.push(tmp);

	return tmp;
};

module.exports = {
	data: new SlashCommandBuilder()
		.setName("meme")
		.setDescription("Shows a random meme.")
		.setDMPermission(true)
		.addIntegerOption(option =>
			option.setName("id")
			.setRequired(false)
			.setDescription("The meme ID")
			.setMinValue(1)),
	is_disabled: false,
	usage: "meme [id]",

	async execute(interaction) {
		let MEMES = get("MEMES");

		if(!MEMES) {
			update("MEMES");
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

		let MEME;
		let rng_res;

		if(!interaction.options && !interaction.options.getInteger("id")) {
			rng_res = rng(MEMES.length);

			MEME = MEMES.find(meme => meme.meme_id == rng_res);
		} else {
			MEME = MEMES.find(meme => meme.meme_id == interaction.options.getInteger("id"));
			rng_res = rng(MEMES.length);

			if(!MEME || !MEME.url) MEME = MEMES.find(meme => meme.meme_id == rng_res);
		};

		if(!MEME || !MEME.url) return interaction.editReply({
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

		let o = {
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor("F44292")
				.setTitle(`Meme with topic: ${MEME ? MEME.topic : "No Topic"}`)
				.setImage(MEME.url)
				.setDescription(MEME.text)
				.setFooter({
					text: `${MEME.credits} - ${MEME.meme_id}`
				})
			],
			data: {
				type: 4,
			}
		};

		interaction.editReply(o).catch(console.error);
	}
};