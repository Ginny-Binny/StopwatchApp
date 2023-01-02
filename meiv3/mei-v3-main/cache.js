const Cars = require("./models/Cars");
const Packs = require("./models/Packs");
const Tracks = require("./models/Tracks");
const Users = require("./models/Users");
const Memes = require("./models/Memes");
const Guilds = require("./models/Guilds");
const Career = require("./models/Career");
const WRs = require("./models/WRs");
const Clips = require("./models/Clips");
const GuessTheCar = require("./models/GTCQuestions");

const cache = {};

module.exports = {
	get(type) {
		switch(type) {
			case "CARS":
				return cache.cars;
			break;

			case "PACKS":
				return cache.packs;
			break;

			case "TRACKS":
				return cache.tracks;
			break;

			case "CAREER":
				return cache.career;
			break;

			case "WRS":
				return cache.wrs;
			break;

			case "USERS":
				return cache.users;
			break;

			case "MEMES":
				return cache.memes;
			break;

			case "GUILDS":
				return cache.guilds;
			break;

			case "BOT":
				return cache.bot;
			break;

			case "COOLDOWN":
				return cache.cooldown;
			break;

			case "DROPS":
				return cache.drops;
			break;

			case "CLIPS":
				return cache.clips;
			break;

			case "GTC":
				return cache.gtc;
			break;
		
			default:
				return cache;
			break;
		};
	},
	update: (type, data) => new Promise((resolve, reject) => {
		switch(type) {
			case "CARS":
				Cars.find({}, (err, cars) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.cars = cars;
		
					resolve(cars);
				}).lean();
			break;

			case "PACKS":
				Packs.find({}, (err, packs) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.packs = packs;
		
					resolve(packs);
				}).lean();
			break;

			case "TRACKS":
				Tracks.find({}, (err, tracks) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.tracks = tracks;
		
					resolve(tracks);
				}).lean();
			break;

			case "CAREER":
				Career.find({}, (err, career) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.career = career;
		
					resolve(career);
				}).lean();
			break;

			case "WRS":
				WRs.find({}, (err, wrs) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.wrs = wrs;
		
					resolve(wrs);
				}).lean();
			break;

			case "USERS":
				Users.find({}, (err, users) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.users = users;
		
					resolve(users);
				}).lean();
			break;

			case "MEMES":
				Memes.find({}, (err, memes) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.memes = memes;
		
					resolve(memes);
				}).lean();
			break;

			case "GUILDS":
				Guilds.find({}, (err, guilds) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.guilds = guilds;
		
					resolve(guilds);
				}).lean();
			break;

			case "CLIPS":
				Clips.find({}, (err, clips) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.clips = clips;
		
					resolve(clips);
				}).lean();
			break;

			case "BOT":
				cache.bot = data;
				
				resolve();
			break;

			case "GTC":
				GuessTheCar.find({}, (err, gtc) => {
					if(err) {
						reject();
						return console.error(err);
					};
					
					cache.gtc = gtc;
		
					resolve(gtc);
				}).lean();
			break;
		
			default:
				cache.cooldown = {};

				cache.drops = {
					packAllDrops: [
						{ id: 71, rarity: "Epic", weight: 1 },
						{ id: 69, rarity: "Epic", weight: 2 },
						{ id: 68, rarity: "Epic", weight: 3 },
						{ id: 52, rarity: "Epic", weight: 4 },
						{ id: 66, rarity: "Epic", weight: 5 },
						{ id: 67, rarity: "Epic", weight: 6 },
						{ id: 78, rarity: "Epic", weight: 7 },
						{ id: 51, rarity: "Epic", weight: 8 },
						{ id: 49, rarity: "Epic", weight: 9 },
						{ id: 77, rarity: "Epic", weight: 10 },
						{ id: 47, rarity: "Epic", weight: 11 },
						{ id: 46, rarity: "Epic", weight: 12 },
						{ id: 33, rarity: "Epic", weight: 13 },
						{ id: 76, rarity: "Epic", weight: 14 },
						{ id: 62, rarity: "Epic", weight: 15 },
						{ id: 45, rarity: "Epic", weight: 16 },
						{ id: 75, rarity: "Epic", weight: 17 },
						{ id: 61, rarity: "Epic", weight: 18 },
						{ id: 44, rarity: "Rare", weight: 19 },
						{ id: 60, rarity: "Epic", weight: 20 },
						{ id: 31, rarity: "Epic", weight: 21 },
						{ id: 43, rarity: "Rare", weight: 22 },
						{ id: 59, rarity: "Rare", weight: 23 },
						{ id: 42, rarity: "Rare", weight: 24 },
						{ id: 58, rarity: "Rare", weight: 25 },
						{ id: 30, rarity: "Rare", weight: 26 },
						{ id: 29, rarity: "Rare", weight: 27 },
						{ id: 57, rarity: "Rare", weight: 28 },
						{ id: 28, rarity: "Rare", weight: 29 },
						{ id: 56, rarity: "Rare", weight: 30 },
						{ id: 27, rarity: "Rare", weight: 31 },
						{ id: 17, rarity: "Rare", weight: 32 },
						{ id: 25, rarity: "Rare", weight: 33 },
						{ id: 39, rarity: "Rare", weight: 34 },
						{ id: 16, rarity: "Rare", weight: 35 },
						{ id: 13, rarity: "Rare", weight: 36 },
						{ id: 36, rarity: "Uncommon", weight: 37 },
						{ id: 12, rarity: "Rare", weight: 38 },
						{ id: 11, rarity: "Rare", weight: 39 },
						{ id: 37, rarity: "Rare", weight: 40 },
						{ id: 23, rarity: "Uncommon", weight: 41 },
						{ id: 10, rarity: "Rare", weight: 42 },
						{ id: 9, rarity: "Rare", weight: 43 },
						{ id: 35, rarity: "Uncommon", weight: 44 },
						{ id: 22, rarity: "Uncommon", weight: 45 },
						{ id: 34, rarity: "Uncommon", weight: 46 },
						{ id: 8, rarity: "Uncommon", weight: 47 },
						{ id: 21, rarity: "Uncommon", weight: 48 },
						{ id: 7, rarity: "Uncommon", weight: 49 },
						{ id: 20, rarity: "Uncommon", weight: 50 },
						{ id: 19, rarity: "Uncommon", weight: 51 },
						{ id: 6, rarity: "Uncommon", weight: 52 },
						{ id: 18, rarity: "Uncommon", weight: 53 },
						{ id: 5, rarity: "Uncommon", weight: 54 },
						{ id: 3, rarity: "Uncommon", weight: 55 },
						{ id: 2, rarity: "Uncommon", weight: 56 },
						{ id: 1, rarity: "Uncommon", weight: 57 }
					],
					packPremiumDrops: [
						{ id: 87, rarity: "Epic", weight: 1 },
						{ id: 86, rarity: "Epic", weight: 2 },
						{ id: 73, rarity: "Epic", weight: 3 },
						{ id: 72, rarity: "Epic", weight: 4 }
					],
					packPurpleDrops: [
						{ id: 83, rarity: "Epic", weight: 1 },
						{ id: 81, rarity: "Epic", weight: 2 },
						{ id: 54, rarity: "Epic", weight: 3 }
					]
				};
				
				Cars.find({}, (cars_err, cars) => {
					if(cars_err) {
						reject();
						return console.error(cars_err);
					};
					
					cache.cars = cars;

					Packs.find({}, (packs_err, packs) => {
						if(packs_err) {
							reject();
							return console.error(packs_err);
						};
						
						cache.packs = packs;
			
						Tracks.find({}, (tracks_err, tracks) => {
							if(tracks_err) {
								reject();
								return console.error(tracks_err);
							};
							
							cache.tracks = tracks;

							Users.find({}, (users_err, users) => {
								if(users_err) {
									reject();
									return console.error(users_err);
								};
								
								cache.users = users;
					
								Memes.find({}, (memes_err, memes) => {
									if(memes_err) {
										reject();
										return console.error(memes_err);
									};
									
									cache.memes = memes;
						
									Guilds.find({}, (guilds_err, guilds) => {
										if(guilds_err) {
											reject();
											return console.error(guilds_err);
										};
										
										cache.guilds = guilds;

										Career.find({}, (career_err, career) => {
											if(career_err) {
												reject();
												return console.error(career_err);
											};
											
											cache.career = career;
								
											WRs.find({}, (wrs_err, wrs) => {
												if(wrs_err) {
													reject();
													return console.error(wrs_err);
												};
												
												cache.wrs = wrs;

												Clips.find({}, (clips_err, clips) => {
													if(clips_err) {
														reject();
														return console.error(clips_err);
													};
													
													cache.clips = clips;

													GuessTheCar.find({}, (err, gtc) => {
														if(err) {
															reject();
															return console.error(err);
														};
														
														cache.gtc = gtc;

														resolve();
													}).lean();
												}).lean();
											}).lean();
										}).lean();
									}).lean();
								}).lean();
							}).lean();
						}).lean();
					}).lean();
				}).lean();
			break;
		};
	}),
};