#include <iostream>
using namespace std;

int main() {
	//cout << " Enter the number of testcases : " << endl;
	int Testcases;
	cin >> Testcases;
	int k;

	for(k = 0; k < Testcases; k++) {

	//cout << "Enter the number of submissions  : " <<  endl;
	int submissions;
	cin >> submissions;

	int i,j;

	int noOfProblems = 8;
	int array[noOfProblems][1];

	for(i = 0; i < noOfProblems; i++) {


			array[i][0] = 0;
	}
		for(j = 0; j < submissions; j++) {
	//	cout << "Enter the problem number and the score you recieved for that problem : " << endl;
		int problemNumber, score;
		cin >> problemNumber >> score;

		if(( problemNumber == 9) || ( problemNumber == 10) || ( problemNumber == 9)) { continue;}
		else if(score > array[problemNumber - 1][0]) {array[problemNumber  - 1][0] = score;}

		}
		int total = 0;
		for(i = 0; i < noOfProblems; i++) {
			total = total + array[i][0];
		}

		cout << total << endl;
	}
	return 0;
}
