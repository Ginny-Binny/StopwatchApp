const config = require("../config.json");
const { MessageEmbed, MessageButton, MessageActionRow } = require("discord.js");
const { SlashCommandBuilder } = require("@discordjs/builders");
const { get, update } = require("../cache");

const merge = require("merge-img");
const Chance = require("chance");
const fs = require("fs");
const Jimp = require("jimp");

const chance = new Chance();

module.exports = {
	data: new SlashCommandBuilder()
		.setName("pack")
		.setDescription("Simulate a pack openning.")
		.setDMPermission(true)
		.addStringOption(option =>
			option.setName("pack")
			.setDescription("Pack name to open")
			.setRequired(true)
			.setAutocomplete(true)),
	is_disabled: false,
	usage: "pack <pack>",

	async execute(interaction) {
		if(!get("COOLDOWN")[interaction.user.id]) get("COOLDOWN")[interaction.user.id] = false;

		if(get("COOLDOWN")[interaction.user.id] === true) return interaction.editReply({
			ephemeral: true,
			embeds: [
				new MessageEmbed()
				.setColor(config.COLORS.red)
				.setTitle(`${config.EMOTES.error} Slow down!`)
			],
			data: {
				type: 4
			}
		}).catch(console.error);

		let packs = get("PACKS");

		if(!packs) {
			update("PACKS");
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

		let pack_details = packs.find(pack => pack.pack_id == interaction.options.get("pack").value.toLowerCase());

		if(!pack_details) {
			return interaction.editReply({
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
		};

		let FEATURED_ITEMS = [];

		let featured_item_infos;

		pack_details.featureds.forEach(featured_item => {
			featured_item_infos = featured_item.toString().split(":");

			FEATURED_ITEMS.push({
				type: featured_item_infos[0],
				id: (featured_item_infos[0] === "key" || featured_item_infos[0] === "epic") ? featured_item_infos[1].split("_")[1].split("x")[0] : Number(featured_item_infos[1].split("x")[0]),
				quantity: (featured_item_infos[0] === "key" || featured_item_infos[0] === "epic") ? featured_item_infos[1].split("_")[1].split("x")[1] : Number(featured_item_infos[1].split("x")[1]),
				weight: Number(featured_item_infos[2]),
			});
		});

		let item_type;
		let item_id;
		let item_amount;

		let POSSIBLES_DROPS = [];

		if(pack_details.regular_drops) POSSIBLES_DROPS = POSSIBLES_DROPS.concat(get("DROPS").packAllDrops.filter(id => !pack_details.featureds.map(val => val.toString().split(":")[1].split("x")[0]).includes(id)));
		if(pack_details.premium_drops) POSSIBLES_DROPS = POSSIBLES_DROPS.concat(get("DROPS").packPremiumDrops.filter(id => !pack_details.featureds.map(val => val.toString().split(":")[1].split("x")[0]).includes(id)));
		if(pack_details.purple_drops) POSSIBLES_DROPS = POSSIBLES_DROPS.concat(get("DROPS").packPurpleDrops.filter(id => !pack_details.featureds.map(val => val.toString().split(":")[1].split("x")[0]).includes(id)));

		let ITEMS = [];

		if(fs.existsSync(`./assets/packs/${pack_details.icon}.png`)) ITEMS.push(`./assets/packs/${pack_details.icon}.png`);

		for(let i = 1; i < (pack_details.cards + 1); i++) {
			//GEN RARITY AND FEATURED OR NOT
			if(i === pack_details.cards && pack_details.lastAlwaysFeatured) {
				item_type = "F";
			} else {
				if(i === pack_details.cards && pack_details.lastAlwaysEpic) {
					item_type = "E";
				} else {
					item_type = chance.weighted(["F", "U", "R", "E"], [
						pack_details.droprates.featured || 0,
						pack_details.droprates.uncommon || 0,
						pack_details.droprates.rare || 0,
						pack_details.droprates.epic || 0
					]);
				};
			};

			//GEN CARS AND ITEMS

			switch(item_type) {
				case "F":
					item_id = chance.weighted(FEATURED_ITEMS, FEATURED_ITEMS.map(val => val.weight));
				break;

				case "U":
					item_id = chance.weighted(POSSIBLES_DROPS.filter(val => val.rarity === "Uncommon"), POSSIBLES_DROPS.filter(val => val.rarity === "Uncommon").map(val => val.weight));
				break;

				case "R":
					item_id = chance.weighted(POSSIBLES_DROPS.filter(val => val.rarity === "Rare"), POSSIBLES_DROPS.filter(val => val.rarity === "Rare").map(val => val.weight));
				break;

				case "E":
					item_id = chance.weighted(POSSIBLES_DROPS.filter(val => val.rarity === "Epic"), POSSIBLES_DROPS.filter(val => val.rarity === "Epic").map(val => val.weight));
				break;
			};

			//GEN AMOUNTS
			switch(item_type) {
				case "F":
					item_amount = item_id.quantity;
				break;

				case "U":
					if(chance.bool({likelihood: 40})) {
						item_amount = 6;
					} else {
						item_amount = 3;
					};
				break;

				case "R":
					if(chance.bool({likelihood: 30})) {
						item_amount = 4;
					} else {
						item_amount = 2;
					};
				break;

				case "E":
					if(chance.bool({likelihood: 15})) {
						item_amount = 3;
					} else {
						item_amount = 1;
					};
				break;
			};

			//GEN PATHS

			if(item_type === "F") {
				if(item_id.type === "bp") {
					ITEMS.push(`./assets/bps/${item_id.id}x${item_amount}.png`);
				} else ITEMS.push(`./assets/specials/${item_id.type}_${item_id.id}.png`);
			} else ITEMS.push(`./assets/bps/${item_id.id}x${item_amount}.png`);
		};

		merge(ITEMS, {
			offset: 20,
			margin: "10 10 10 10"
		}).then(img => {
			img.getBuffer(Jimp.MIME_PNG, (err, buffer) => {
				interaction.editReply({
					files: [{
						attachment: buffer,
						name: `${interaction.id}.png`
					}]
				}).then(() => {
					get("COOLDOWN")[interaction.user.id] = false;
				}).catch(e => {
					console.error(e);

					get("COOLDOWN")[interaction.user.id] = false;

					return interaction.editReply({
						ephemeral: true,
						embeds: [
							new MessageEmbed()
							.setColor(config.COLORS.red)
							.setTitle(`${config.EMOTES.error} An error occured.`)
						],
						data: {
							type: 4,
						}
					}).catch(console.error);
				});
			});
		})
		.catch(e => {
			console.error(e);

			get("COOLDOWN")[interaction.user.id] = false;

			return interaction.editReply({
				ephemeral: true,
				embeds: [
					new MessageEmbed()
					.setColor(config.COLORS.red)
					.setTitle(`${config.EMOTES.error} An error occured while creating the image.`)
				],
				data: {
					type: 4,
				}
			}).catch(console.error);
		});
	},

	async autocomplete(interaction) {
		let focusedValue = interaction.options.getFocused();

		let packs = get("PACKS");

		let filtered = packs.filter(pack => pack.pack_id.startsWith(focusedValue)).slice(0, 10);

		await interaction.respond(filtered.map(choice => ({
			name: choice.display_name,
			value: choice.pack_id.toString()
		})));
	}
};