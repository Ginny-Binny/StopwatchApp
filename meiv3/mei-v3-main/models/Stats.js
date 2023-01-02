const Mongoose = require("mongoose");

let Schema = Mongoose.Schema({
	type: String,
	value: Number
});

module.exports = Mongoose.model("Stats", Schema);