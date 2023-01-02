require("dotenv").config();

const fs = require("fs");
const Mongoose = require("mongoose");
const cache = require("./cache");
const { REST } = require("@discordjs/rest");
const { Client, Intents, Collection, VoiceBroadcast } = require("discord.js");
const { Routes } = require("discord-api-types/v9");

const config = require("./config.json");

const bot = new Client({
	intents: [
		Intents.FLAGS.GUILDS,
		Intents.FLAGS.GUILD_MESSAGES,
		Intents.FLAGS.DIRECT_MESSAGES
	]
});

const commandsFiles = fs.readdirSync(config.COMMANDS_DIR).filter(file => file.endsWith(".js"));
const commands = [];
const localCommands = [];

bot.commands = new Collection();
bot.localCommands = new Collection();

for(let file of commandsFiles) {
	let command = require(`${config.COMMANDS_DIR}/${file}`);

	if(!command.is_disabled) {
		if(command.only_for && command.only_for.length > 0) {
			localCommands.push(command.data.toJSON());
			bot.localCommands.set(command.data.name, command);
		} else {
			commands.push(command.data.toJSON());
			bot.commands.set(command.data.name, command);
		};
	};
};

bot.once("ready", () => {
	bot.user.setActivity(config.ACTIVITY.name, {
		type: config.ACTIVITY.type,
	});

	console.log("Bot ready.");

	let CLIENT_ID = bot.user.id;

	let rest = new REST({
		version: "9"
	}).setToken(process.env.TOKEN);

	(async () => {
		try {
			if(process.env.ENV === "production") {
				await rest.put(Routes.applicationCommands(CLIENT_ID), {
					body: commands
				});
				console.log("Registered commands globally.");
			} else {
				await rest.put(Routes.applicationGuildCommands(CLIENT_ID, config.TEST_GUILD_ID), {
					body: commands
				});
				console.log("Registered commands locally.");
			};
		} catch(err) {
			if(err) console.error(err);
		};
	})();
});

bot.on("interactionCreate", (interaction) => {
	if(interaction.isCommand()) {
		let command = interaction.client.commands.get(interaction.commandName);

		if(!command) return;
		if(command.is_disabled) return;
	
		interaction.deferReply().then(() => {
			try {
				command.execute(interaction);
			} catch(err) {
				if(err) console.error(err);
		
				interaction.editReply({
					ephemeral: true,
					embeds: [
						new MessageEmbed()
						.setColor(config.COLORS.red)
						.setTitle(`${config.EMOTES.error} An error occured, please try again.`)
					],
					data: {
						type: 4
					}
				}).catch(() => {});
			};
		}).catch(() => {});
	};

	if(interaction.isAutocomplete()) {
		let command = interaction.client.commands.get(interaction.commandName);

		if(!command) return;
		if(command.is_disabled) return;

		try {
			command.autocomplete(interaction);
		} catch(err) {
			if(err) return console.error(err);
		};
	};

	/*if(interaction.isButton()) {
		let command = interaction.client.commands.get(interaction.commandName);

		if(!command) return;
		if(command.is_disabled) return;

		try {
			command.button(interaction);
		} catch(err) {
			if(err) return console.error(err);
		};
	};*/
});

Mongoose.connect(`mongodb://${process.env.DB_HOST}:${process.env.DB_PORT}/${process.env.DB_NAME}`, {
	useNewUrlParser: true,
	useUnifiedTopology: true,
	ssl: true,
	user: process.env.DB_USER,
	pass: process.env.DB_PASS
}, err => {
	if(err) {
		console.error(err);
		return process.exit(1);
	};

	console.log("DB ready.");

	cache.update();
	cache.update("BOT", bot);
});

bot.login(process.env.TOKEN);

//WEBSITE

const favicon = require("serve-favicon");
const device = require("express-device");
const express = require("express");
const helmet = require("helmet");
const path = require("path");

const PORT = process.env.PORT || 3000;

const app = express();

app.use(favicon(path.join(__dirname, "wbs", "views", "favicon.ico")));
app.use(express.static("wbs/public"));
app.set("view engine", "pug");
app.set("views", path.join(__dirname, "wbs", "views"));
app.use(helmet({
	crossOriginEmbedderPolicy: false,
	crossOriginResourcePolicy: false,
	contentSecurityPolicy: {
		directives: {
			defaultSrc: [
				"'self'",
				"'unsafe-inline'"
			],
			scriptSrc: [
				"'self'",
				"maxcdn.bootstrapcdn.com",
				"code.jquery.com",
				"cdn.jsdelivr.net",
				"'unsafe-inline'"
			],
	  		styleSrc: [
				"'self'",
				"maxcdn.bootstrapcdn.com",
				"'unsafe-inline'"
			],
	  		fontSrc: [
				"'self'",
				"maxcdn.bootstrapcdn.com",
				"'unsafe-inline'"
			],
			imgSrc: [
				"'self'",
				"data:",
				"i.imgur.com",
				"media.discordapp.net",
				"i0.wp.com",
				"i1.wp.com",
				"i2.wp.com"
			]
		}
	}
}));

app.use(device.capture());

device.enableDeviceHelpers(app);

require("./wbs/router")(app);

app.listen(PORT, () => {
	console.log(`WEBSITE ON ${PORT}`);
});