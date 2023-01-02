const mongoose = require("mongoose");

let Schema = mongoose.Schema({
	id: String,
	display_name: String,
	platform: String,
	count: String,
	track_id: String,
	updated_at: Date,
	logs: Array,
	tiers: String
});

module.exports = mongoose.model("Events", Schema);