const mongoose = require("mongoose");

let Schema = mongoose.Schema({
	id: String,
	image: String,
	level: String,
	choices: Array
});

module.exports = mongoose.model("GTCQuestions", Schema);