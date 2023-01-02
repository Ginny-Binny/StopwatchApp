const mongoose = require("mongoose");

let Schema = new mongoose.Schema({
	player_name: String,
	player_channel: String,
	car: String,
	track: String,
	rank: String,
	time: String,
	video: String,
	verified: Boolean,
	skip_to: Number,
	submitted_at: Date,
	comment: String
});

module.exports = mongoose.model("WRs", Schema);