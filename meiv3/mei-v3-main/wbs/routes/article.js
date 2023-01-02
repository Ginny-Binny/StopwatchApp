const router = require("express").Router();

const navs = require("../navs.json");

const News = require("../../models/News");

router.get("/", (req, res) => {
    if(!req.query.id) return res.status(404).render("not_found", {
        title: "MEI - Not Found",
        navs: navs
    });

	News.find({}, (ERR, NEWS) => {
        let article = NEWS.find(a => a.news_id === req.query.id);

        if(!article) return res.status(404).render("not_found", {
            title: "MEI - Not Found",
            navs: navs
        });

        res.status(200).render("article", {
            title: `MEI - ${article.title}`,
            article: article,
            navs: navs
        });

        article.views++;
        article.markModified("views");
        article.save();
    });
});

module.exports = router;