const config = require("../config.json");
const { MessageEmbed, MessageButton, MessageActionRow } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { get } = require("../cache");
const Chance = require("chance");

const chance = new Chance();

module.exports = {
	data: new SlashCommandBuilder()
		.setName("guessthecar")
		.setDescription("Guess the car.")
		.setDMPermission(true)
        .addStringOption(option =>
			option.setName("difficulty")
			.addChoices(
				{
					name: "EASY",
					value: "EASY"
				},
				{
					name: "HARD",
					value: "HARD"
				},
				{
					name: "EXTREM",
					value: "EXTREM"
				}
			)
			.setDescription("Difficulty level")
			.setRequired(false)),
	is_disabled: false,
	usage: "guessthecar",

	async execute(interaction) {
		let difficulty;

		if(!interaction.options.get("difficulty")) {
			difficulty = "HARD";
		} else {
			if(!["EASY", "HARD", "EXTREM"].includes(interaction.options.get("difficulty").value)) {
				return interaction.editReply({
					ephemeral: true,
					embeds: [
						new MessageEmbed()
						.setColor(config.COLORS.red)
						.setTitle(`${config.EMOTES.error} Wrong difficulty.`)
					],
					data: {
						type: 4
					}
				}).catch(console.error);
			} else difficulty = interaction.options.get("difficulty").value.toString().toUpperCase();
		};

		let questions = get("GTC").filter(question => question.level === difficulty);

		if(!questions || questions.length === 0) return interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.red)
				.setTitle(`${config.EMOTES.error} None of the results match.`)
			],
			data: {
				type: 4,
			}
		}).catch(console.error);

		let question = chance.pickone(questions);

		let choices = [];

		question.choices.forEach((choice, index) => {
			choices.push({
				id: index.toString(),
				name: choice.name,
				right: choice.right
			});
		});

		choices = chance.shuffle(choices);

		interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.blue)
				.setTitle(`GUESS THE CAR - ${question.level}`)
				.setImage(question.image)
			],
			components: [
				new MessageActionRow()
				.addComponents(
					new MessageButton()
						.setCustomId(choices[0].id)
						.setLabel(choices[0].name)
						.setStyle("PRIMARY")
						.setDisabled(false),
					new MessageButton()
						.setCustomId(choices[1].id)
						.setLabel(choices[1].name)
						.setStyle("PRIMARY")
						.setDisabled(false),
					new MessageButton()
						.setCustomId(choices[2].id)
						.setLabel(choices[2].name)
						.setStyle("PRIMARY")
						.setDisabled(false),
				)
			],
			data: {
				type: 4,
			}
		}).then(PANEL => {
			PANEL.awaitMessageComponent({
				filter: (i => i.user.id === interaction.user.id),
				time: 450000,
				componentType: "BUTTON"
			}).then(i => {
				i.deferReply().then(() => {
					let answer = Number(i.customId);

					let panel_result = "";

					let calculated_score = 0;

					if(choices.find(choice => choice.id === answer.toString()).right) {
						calculated_score =+ 10;

						panel_result = `💯 You're right! You just scored **${calculated_score}**`;
					} else {
						calculated_score =- 10;
						panel_result = `🚫 You're wrong! You just scored **${calculated_score}**`;
					};

					i.editReply({
						ephemeral: true,
						embeds: [
							new MessageEmbed()
							.setColor(config.COLORS.blue)
							.setTitle(panel_result)
						],
						data: {
							type: 4,
						}
					}).catch(console.error);
				}).catch(console.error);
			}).catch(console.error);
		}).catch(console.error);
	}
};