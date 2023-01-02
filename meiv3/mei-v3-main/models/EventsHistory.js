const mongoose = require("mongoose");

let Schema = mongoose.Schema({
	id: String,
	display_name: String,
	platform: String,
	count: String,
	track_id: String,
	logs: Array,
	deleted_at: Date
});

module.exports = mongoose.model("EventsHistory", Schema);