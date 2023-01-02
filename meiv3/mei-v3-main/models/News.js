const mongoose = require("mongoose");

let Schema = mongoose.Schema({
	news_id: String,
    date: Date,
    title: String,
    image: String,
    description: String,
    content: Array,
    views: Number,
    author: String
});

module.exports = mongoose.model("News", Schema);