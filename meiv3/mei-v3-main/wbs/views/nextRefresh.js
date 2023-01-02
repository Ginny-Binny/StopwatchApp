let now;
let this_hour;
let this_mins;
let next_refresh;
let time_left;
let next_refresh_date;
let diff;
let tmp;

function dateDiff(date1, date2) {
	diff = {}
	tmp = date2 - date1;

	tmp = Math.floor(tmp / 1000);
	diff.sec = tmp % 60;

	if(diff.sec.toString().length !== 2) diff.sec = "0" + diff.sec;

	tmp = Math.floor((tmp - diff.sec) / 60);
	diff.min = tmp % 60;

	if(diff.min.toString().length !== 2) diff.min = "0" + diff.min;

	tmp = Math.floor((tmp - diff.min) / 60);
	diff.hour = tmp % 24;

	if(diff.hour.toString().length !== 2) diff.hour = "0" + diff.hour;

	return diff;
};

function refresh() {
	now = new Date();
	this_hour = now.getUTCHours();
	this_mins = now.getUTCMinutes();

	now.setHours(this_hour);
	now.setMinutes(this_mins);

	if(this_hour >= 10 && this_hour < 12) {
		next_refresh = 12;
	} else {
		if(this_hour >= 12 && this_hour < 18) {
			next_refresh = 18
		} else {
			next_refresh = 10;
		};
	};

	next_refresh_date = new Date();
	next_refresh_date.setHours(next_refresh);
	next_refresh_date.setMinutes(00);
	next_refresh_date.setSeconds(00);
	next_refresh_date.setMilliseconds(00);

	if(next_refresh === 10) next_refresh_date.setDate(next_refresh_date.getDate() + 1);

	diff = dateDiff(now, next_refresh_date);

	time_left = `${diff.hour}h ${diff.min}mn ${diff.sec}s`;

	document.getElementById("next-refresh").innerHTML = time_left;
	success();
};

function success() {
	setTimeout(refresh, 500);
};

$(() => {
	refresh();
});