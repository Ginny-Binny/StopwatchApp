const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");

const lines = {
	clubs: [
		"",
		"[1% Team](https://discord.gg/Y75E27P)",
		"[A9™](https://discord.gg/ZWNmR9z)",
		"[AC](https://discord.gg/bRxpExT)",
		"[ACES](https://discord.gg/47sN522)",
		"[Airwalkers™](https://discord.gg/9eyqY4B)",
		"[BD Tiger™](https://discord.gg/hrG2JpD)",
		"[Beach Boyz](https://discord.gg/eM6Rjsy)",
		"[Bodensee](https://discord.gg/ARgHKck)",
		"[BRE](https://discord.gg/HbaQZ2r)",
		"[Club53™️](https://discord.gg/Rg3txQE)",
		"[Elite Team](https://discord.gg/CygFCYR)",
		"[Fury](https://discord.gg/z68pXay)",
		"[Ghost UA](https://discord.gg/zWtbxF4)",
		"[GREEN LEGENDS™](https://discord.gg/nf2mCAGZ66)",
		"[Hispanic Revenge™](https://discord.gg/rkrr5pJ)",
		"[Ikisport](https://discord.gg/vVYAVCQ)",
		"[ISR™](https://discord.gg/u2S8Zpe)",
		"[Kolbenƒresser](https://discord.gg/9hhFtv5)",
		"[LeMans](https://discord.gg/38pdzed)",
		"[Legions United](https://discord.gg/yXPeddt7pj)",
		"[MilkyWay™](https://discord.gg/HzdE8cF)",
		"[Team Pakistan](https://discord.gg/6cs5rAZ)",
		"[PC™](https://discord.gg/wcQAqdj)",
		"[PHANTOM](https://discord.gg/SkKyk3FEuq)",
		"[PRO™](https://discord.gg/ZquzzeB)",
		"[Reborn](https://discord.gg/587e8eR)",
		"[Red Bulls](https://discord.gg/HyxFsd3) - EXPIRED",
		"[ReV](https://discord.gg/eaCsF7R)",
		"[Road Master](https://discord.gg/F97Xj2m)",
		"[RpM](https://discord.gg/nD2ne8D)",
		"[Snowmen](https://discord.gg/2XUjqx7)",
		"[Sonic Boom™](https://discord.gg/cBMghA3)",
		"[THE HIVE](https://discord.gg/VyDDycY)",
		"[Surgical Striker](https://discord.gg/8WAqkYt)",
		"[T.A.](https://discord.gg/xUE3yW3FxD)",
		"[TGL](https://discord.gg/3AQvS65)",
		"[The Legends](https://discord.gg/uA5yS2u)",
		"[The Stigs](https://discord.gg/EDzWy2x)",
		"[Ghost[UA]](https://discord.gg/zWtbxF4)",
		"[TRU](https://discordapp.com/invite/S5jpvb9)",
		"[UERK](https://discord.gg/apuwhPf)",
		"[WWC](https://discord.gg/F5E4zKD)"
	],
	others: [
		"",
		"[no/Drama A9](https://discord.gg/Qg23TjG)",
		"[fb/Asphalt 9: Legends](https://discord.gg/2n938Ne) - EXPIRED",
		"[Purple Team](https://discord.gg/ftsSfWg)",
		"[United Stand](https://discord.gg/5Cg8CXr)",
		"[WILD](https://discord.gg/ZNGdMRD)",
		"[Asphalt 9 - Offical](https://discord.gg/asphalt9)",
		"[MEI Support](https://discord.gg/KgKMgxd)"
	]
};

module.exports = {
	data: new SlashCommandBuilder()
		.setName("discords")
		.setDescription("List of populars discords servers.")
		.setDMPermission(true),
	is_disabled: false,
	usage: "discords",

	async execute(interaction) {
		interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.blue)
				.setAuthor({
					name: "Clubs",
					iconURL: "https://i.imgur.com/Dgk4Yhk.png"
				})
				.setDescription(lines.clubs.join("\n**-** ")),

				new MessageEmbed()
				.setColor(config.COLORS.blue)
				.setAuthor({
					name: "Others",
					iconURL: "https://i.imgur.com/Dgk4Yhk.png"
				})
				.setDescription(lines.others.join("\n**-** "))
			],
			data: {
				type: 4,
			}
		}).catch(console.error);
	}
};