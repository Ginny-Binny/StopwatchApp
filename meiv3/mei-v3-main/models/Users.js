const Mongoose = require("mongoose");

let Schema = Mongoose.Schema({
	user_id: String,
	is_switch_mode_on: Boolean,
	is_vip: Boolean,
	is_restricted: Boolean,
	username: String,
	avatar_url: String,
	platform: String,
	unit: String,
	requests: Object,
	packs: Object
});

module.exports = Mongoose.model("Users", Schema);