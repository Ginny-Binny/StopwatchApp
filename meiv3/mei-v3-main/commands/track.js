const config = require("../config.json");
const { MessageEmbed } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { get, update } = require("../cache");
const JsSearch = require("js-search");
const Table = require("table");

module.exports = {
	data: new SlashCommandBuilder()
		.setName("track")
		.setDescription("Show where a track is available in career.")
		.setDMPermission(true)
		.addStringOption(option =>
			option.setName("track")
			.setRequired(true)
			.setAutocomplete(true)
			.setDescription("The name of the track")),
	is_disabled: false,
	usage: "track [track]",

	async execute(interaction) {
		let tracks = get("TRACKS");

		if(!tracks) {
			update("TRACKS");
			throw "No cache";
		};

		let track_details = tracks.find(track => track.track_id.toString() === interaction.options.get("track").value.toString());

		if(!track_details) {
			return interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.red)
					.setTitle(`${config.EMOTES.error} None of the results match.`)
					.setDescription("Valid examples: thousand, downtown")
				],
				data: {
					type: 4,
				}
			}).catch(console.error);
		};

		let list = [];

		let career = get("CAREER");

		if(!career) {
			update("CAREER");
			throw "No cache";
		};

		career.forEach(chap => {
			chap.seasons.forEach(season => {
				season.races.forEach(race => {
					if(race.track_id == track_details.track_id) {
						list.push({
							chapter_id: chap.chapter.id,
							chapter: chap.chapter.name,
							season_id: season.id,
							season: season.name,
							season_logo: season.icon ? season.icon : undefined,
							race_id: race.id,
							rank: race.rank,
							mode: race.mode,
							track_id: race.track_id,
							credits: race.credits,
							cars: race.cars,
							bots: race.bots ? race.bots : undefined,
							laps: race.laps ? race.laps : undefined
						});
					};
				});
			});
		});

		let embed = new MessageEmbed()
		.setFooter({
			text: `⚠️ Legendary Start and Gearheads season does not work with LP tasks.
Saw incorrect data? Tell us with /feedback
ID: ${track_details.track_id}`
		})
		.setColor(config.COLORS.blue)
		.setAuthor({
			name: `${track_details.location.toUpperCase()} - ${track_details.track}`,
			iconURL: "https://i.imgur.com/F3S99fJ.png",
			url: `https://mei-a9.herokuapp.com/tracks?track=${track_details.track_id}`
		});

		let tables = [];

		let y = 0;
		let t = [
			["CHAP", "SEASON", "RACE", "MODE", " "]
		];

		list.forEach(line => {
			if(y === 15) {
				tables.push(t);

				t = [
					["CHAP", "SEASON", "RACE", "MODE", " "],
					[line.chapter_id, line.season, line.race_id, line.mode, line.laps ? `${line.laps} laps` : " "]
				];

				y = 1;
			} else {
				t.push([line.chapter_id, line.season, line.race_id, line.mode, line.laps ? `${line.laps} laps` : " "]);

				y++;
			};
		});

		tables.push(t);

		let embeds = [];

		if(list.length !== 0) {
			embeds.push(embed.setDescription(`\`\`\`
${Table.table(tables[0], {
	border: Table.getBorderCharacters("void")
})}
\`\`\``));
			
			tables.slice(1).forEach(table => {
				embeds.push(new MessageEmbed()
					.setColor(config.COLORS.blue)
					.setDescription(`\`\`\`
${Table.table(table, {
	border: Table.getBorderCharacters("void")
})}
\`\`\``));
			});
		} else {
			embed.setDescription(`\`\`\`
No results...
\`\`\``);
			embeds.push(embed);
		};

		interaction.editReply({
			ephemeral: true,
			embeds: embeds,
			data: {
				type: 4,
			}
		}).catch(console.error);
	},
	async autocomplete(interaction) {
		let focusedValue = interaction.options.getFocused();
		let search = new JsSearch.Search("track_id");

		search.addIndex("track");
		search.addDocuments(get("TRACKS"));

		let filtered = search.search(focusedValue).slice(0, 10);

		await interaction.respond(filtered.map(choice => ({
			name: `${choice.location} ${choice.track}`.toUpperCase(),
			value: choice.track_id.toString()
		})));
	}
};