require("dotenv").config();

const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { GoogleSpreadsheet } = require("google-spreadsheet");
const Events = require("../models/Events");
const { get, update } = require("../cache");

const platforms = [
	"WINDOWS",
	"ANDROID",
	"IOS"
];

module.exports = {
	data: new SlashCommandBuilder()
		.setName("refresh")
		.setDescription("!")
		.setDMPermission(true),
	is_disabled: false,
	usage: "refresh",

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

		let tmp;

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

		SHEET.loadInfo().then(() => {
			Events.find({}, (err, res) => {
				if(err || !res) return console.log(err);

				SHEET.sheetsByIndex.forEach(page => {
					if(!platforms.includes(page.title)) return;
	
					page.getRows().then(rows => {
						rows.forEach(row => {
							tmp = res.find(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase());

							if(!tmp) {
								Events.create({
									id: row._rawData[0].toLowerCase(),
									display_name: row._rawData[2].toUpperCase() || "ERR",
									platform: page.title.toLowerCase(),
									count: Number(row._rawData[1]) || 0,
									track_id: row._rawData[3] || "1",
									updated_at: Date.now(),
									logs: [
										{
											at: Date.now(),
											value: Number(row._rawData[1]) || 0
										}
									],
									tiers: row._rawData[4] || "1/5/25/50/75/100"
								}).then(() => {
									interaction.editReply({
										ephemeral: true,
										embeds: [
											new MessageEmbed()
											.setColor(config.COLORS.green)
											.setTitle(`${config.EMOTES.success} [${page.title}] Created '${row._rawData[2].toUpperCase()}' on ${tracks.find(t => t.track_id == row._rawData[3]) ? tracks.find(t => t.track_id == row._rawData[3]).track : "??"}. \`ID: ${row._rawData[0].toLowerCase()}\`.`)
										],
										data: {
											type: 4,
										}
									}).catch(console.error);
								});
							} else {
								if(tmp.count != Number(row._rawData[1])) {
									res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].count = Number(row._rawData[1]);

									res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].logs.push({
										at: Date.now(),
										value: Number(row._rawData[1])
									});

									res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].updated_at = Date.now();

									res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].markModified("count");
									res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].markModified("logs");
									res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].markModified("updated_at");

									res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())]
									.save()
									.then(() => {
										interaction.editReply({
											ephemeral: true,
											embeds: [
												new MessageEmbed()
												.setColor(config.COLORS.green)
												.setTitle(`${config.EMOTES.success} [${page.title}] Updated '${row._rawData[2].toUpperCase()}' to \`${Number(row._rawData[1])}\`.`)
											],
											data: {
												type: 4,
											}
										}).catch(console.error);
									});
								} else {
									if(tmp.track_id != row._rawData[3]) {
										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].track_id = row._rawData[3];

										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].markModified("track_id");

										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())]
										.save()
										.then(() => {
											interaction.editReply({
												ephemeral: true,
												embeds: [
													new MessageEmbed()
													.setColor(config.COLORS.green)
													.setTitle(`${config.EMOTES.success} [${page.title}] Updated '${row._rawData[2].toUpperCase()}' to be on \`${tracks.find(t => t.track_id === row._rawData[3].toString())}\`.`)
												],
												data: {
													type: 4,
												}
											}).catch(console.error);
										});
									};

									if(tmp.display_name != row._rawData[2].toUpperCase()) {
										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].display_name = row._rawData[2].toUpperCase();

										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].markModified("display_name");

										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())]
										.save()
										.then(() => {
											interaction.editReply({
												ephemeral: true,
												embeds: [
													new MessageEmbed()
													.setColor(config.COLORS.green)
													.setTitle(`${config.EMOTES.success} [${page.title}] Updated '${row._rawData[2].toUpperCase()}' name to \`${row._rawData[2].toUpperCase()}\`.`)
												],
												data: {
													type: 4,
												}
											}).catch(console.error);
										});
									};

									if(tmp.tiers !== row._rawData[4]) {
										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].tiers = row._rawData[4];

										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())].markModified("tiers");

										res[res.findIndex(doc => doc.platform === page.title.toLowerCase() && doc.id === row._rawData[0].toLowerCase())]
										.save()
										.then(() => {
											interaction.editReply({
												ephemeral: true,
												embeds: [
													new MessageEmbed()
													.setColor(config.COLORS.green)
													.setTitle(`${config.EMOTES.success} [${page.title}] Updated '${row._rawData[2].toUpperCase()}', tiers: ${row._rawData[4]}`)
												],
												data: {
													type: 4,
												}
											}).catch(console.error);
										});
									};
								};
							};
						});
					});
				});
			});
		});
	}
};