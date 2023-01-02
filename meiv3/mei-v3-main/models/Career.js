const Mongoose = require("mongoose");

let Schema = Mongoose.Schema({
	seasons: Array,
	chapter: Object,
	flags: Number
});

module.exports = Mongoose.model("Career", Schema);