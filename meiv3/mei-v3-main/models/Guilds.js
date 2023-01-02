const Mongoose = require("mongoose");

let Schema = Mongoose.Schema({
	server_id: String,
	prefix: String,
	is_switch_mode_on: Boolean,
	is_vip: Boolean,
	is_restricted: Boolean,
	plugins: Object,
	banned_commands: Array
});

module.exports = Mongoose.model("Guilds", Schema);