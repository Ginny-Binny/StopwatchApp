const mongoose = require("mongoose");

let Schema = mongoose.Schema({
	url: String,
	author: String,
	author_id: String,
	message_id: String,
	at: Date
});

module.exports = mongoose.model("Clips", Schema);