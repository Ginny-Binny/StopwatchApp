function myFunction() {
	let input, filter, table, tr, td, i, txtValue;
	input = document.getElementById("searchbar");
	filter = input.value.toUpperCase();
	table = document.getElementById("list");
	tr = table.getElementsByTagName("tr");

	let d_check = document.getElementById("class_d");
	let c_check = document.getElementById("class_c");
	let b_check = document.getElementById("class_b");
	let a_check = document.getElementById("class_a");
	let s_check = document.getElementById("class_s");

	for(i = 0; i < tr.length; i++) {
		td = tr[i].getElementsByTagName("td");
		if(td[0]) {
			txtValue = `${td[0].textContent || td[0].innerText}`;
			if(txtValue.toUpperCase().indexOf(filter) > -1) {
				if(!d_check.checked && `${td[1].textContent || td[1].innerText}` === "D") return tr[i].style.display = "none";
				if(!c_check.checked && `${td[1].textContent || td[1].innerText}` === "C") return tr[i].style.display = "none";
				if(!b_check.checked && `${td[1].textContent || td[1].innerText}` === "B") return tr[i].style.display = "none";
				if(!a_check.checked && `${td[1].textContent || td[1].innerText}` === "A") return tr[i].style.display = "none";
				if(!s_check.checked && `${td[1].textContent || td[1].innerText}` === "S") return tr[i].style.display = "none";
				
				tr[i].style.display = "";
			} else {
				tr[i].style.display = "none";
			};
		};
	};
};

function checkbox(CLASS) {
	let table, tr, td, i, txtValue, clickedbox;
	clickedbox = document.getElementById(`class_${CLASS.toLowerCase()}`);
	table = document.getElementById("list");
	tr = table.getElementsByTagName("tr");

	for(i = 0; i < tr.length; i++) {
		td = tr[i].getElementsByTagName("td");
		if(td[1]) {
			txtValue = `${td[1].textContent || td[1].innerText}`;
			
			if(txtValue === CLASS) {
				if(clickedbox.checked) {
					if(document.getElementById("searchbar").value.toUpperCase() !== "") {
						if(td[0]) {
							_txtValue = `${td[0].textContent || td[0].innerText}`;
							if(_txtValue.toUpperCase().indexOf(document.getElementById("searchbar").value.toUpperCase()) > -1) {
								tr[i].style.display = "";
							} else {
								tr[i].style.display = "none";
							};
						};
					} else {
						tr[i].style.display = "";
					};
				} else {
					tr[i].style.display = "none";
				};
			};
		};
	};
};