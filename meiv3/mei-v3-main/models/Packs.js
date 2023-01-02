const mongoose = require("mongoose");

let Schema = mongoose.Schema({
	pack_id: String,
	display_name: String,
	icon: String,

	regular_drops: Boolean,
	premium_drops: Boolean,
	purple_drops: Boolean,

	droprates: Object,

	featureds: Array,

	cost: Number,
	cards: Number,

	tags: Array,

	feed: Boolean,
	creator: String,
	custom: Boolean,
	lastAlwaysFeatured: Boolean,
	lastAlwaysEpic: Boolean
});

module.exports = mongoose.model("Packs", Schema);