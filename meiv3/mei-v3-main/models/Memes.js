const mongoose = require("mongoose");

const Schema = mongoose.Schema({
	meme_id: String,
	topic: String,
	text: String,
	credits: String,
	url: String
});

module.exports = mongoose.model("Memes", Schema);