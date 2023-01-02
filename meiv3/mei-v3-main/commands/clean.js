require("dotenv").config();

const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { GoogleSpreadsheet } = require("google-spreadsheet");
const Events = require("../models/Events");
const EventsHistory = require("../models/EventsHistory");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("clean")
		.setDescription("!")
		.setDMPermission(true),
	is_disabled: false,
	usage: "clean",

	async execute(interaction) {
		let ids = [
			"247369303899242506",
			"590453750523756550",
			"575380608768016394",
			"613211071016075274",
			"757415120119922758",
			"717651754912710706",
			"601853373553311754",
			"673506349816086578",
			"511960102870188042",
			"769498243989110794",
			"571212273973067786",
			"452119503329951764"
		];

		if(!ids.includes(interaction.user.id)) return interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.red)
				.setTitle(`${config.EMOTES.error} You are not allowed to do this.`)
			],
			data: {
				type: 4
			}
		}).catch(console.error);

		let SHEET = new GoogleSpreadsheet("1gJYqrERpYjmlYSeTnAd1jDfT8JQ3PeSebKuCOfxT24k");

		SHEET.useApiKey(process.env.GOOGLE);

		SHEET.loadInfo().then(() => {
			Events.find({}, (err, res) => {
				if(err || !res) return console.log(err);

				let temp = [];

				res.forEach(doc => {
					SHEET.sheetsByIndex.forEach(page => {
						if(doc.platform.toUpperCase() !== page.title.toUpperCase()) return;
		
						page.getRows().then(rows => {
							if(!rows.find(row => row._rawData[0].toLowerCase() === doc.id)) {
								doc.delete().then(() => {
									temp.push(`[${doc.platform.toUpperCase()}] ${doc.id}`)

									EventsHistory.create({
										id: doc.id,
										display_name: doc.display_name,
										platform: doc.platform,
										count: doc.count,
										track_id: doc.track_id,
										logs: doc.logs,
										deleted_at: Date.now()
									});
								});
							};
						});
					});
				});

				if(temp.length === 0) {
					interaction.editReply({
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
				} else {
					interaction.editReply({
						ephemeral: true,
						embeds: [
							new MessageEmbed()
							.setColor(config.COLORS.green)
							.setTitle(`${config.EMOTES.success} Cleaned.`)
							.setDescription(`
\`\`\`
${temp.join("\n")}
\`\`\``)
						],
						data: {
							type: 4,
						}
					}).catch(console.error);
				};
			});
		});
	}
};