// CPP program to find largest power of
// a number (which may be composite) that
// divides factorial.
#include <bits/stdc++.h>
using namespace std;

// for find maximum power of prime number
// p which can divide fact number
int findPowerPrime(int fact, int p)
{
	int res = 0;
	while (fact > 0) {
		res += fact / p;
		fact /= p;
	}

	return res;
}

// Returns sum of all factors of n.
int findPowerComposite(int fact, int n)
{
	// To store result (minimum power of a
	// prime factor that divides fact! )
	int res = INT_MAX;

	// Traverse through all prime factors
	// of n.
	for (int i = 2; i <= sqrt(n); i++) {

		// counter for count the
		// power of prime number
		int count = 0;
		while (n % i == 0) {
			count++;
			n = n / i;
		}

		if (count > 0) {

			// Maximum power of i that divides
			// fact!. We divide by count to handle
			// multiple occurrences of a prime factor.
			int curr_pow = findPowerPrime(fact, i) / count;
			res = min(res, curr_pow);
		}
	}

	// This condition is to handle
	// the case when n is a prime
	// number greater than 2.
	if (n >= 2) {
		int curr_pow = findPowerPrime(fact, n);
		res = min(res, curr_pow);
	}

	return res;
}

// Driver code
int main()
{
	int fact = 80, n = 24;
	
	// Function Call
	cout << findPowerComposite(fact, n);
	return 0;
}
