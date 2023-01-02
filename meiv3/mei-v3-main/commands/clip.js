const config = require("../config.json");
const { SlashCommandBuilder } = require("@discordjs/builders");
const Chance = require("chance");
const moment = require("moment");
const { get } = require("../cache");

const chance = new Chance();

module.exports = {
	data: new SlashCommandBuilder()
		.setName("clip")
		.setDescription("Shows a random clip.")
		.setDMPermission(true),
	is_disabled: false,
	usage: "clip",

	async execute(interaction) {
		let clips = get("CLIPS");

		if(!clips) {
			update("CLIPS");
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

        let clip = chance.shuffle(clips)[0];

		interaction.editReply(`${clip.author} - ${moment(clip.at).format("DD/MM/YYYY")}

        Warning: clips can have loud sound.
        
        ${clip.url}`).catch(console.error);
	}
};