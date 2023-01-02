const Mongoose = require("mongoose");

let Schema = Mongoose.Schema({
	track_id: Number,
	length: Number,
	location: String,
	track: String
});

module.exports = Mongoose.model("Tracks", Schema);