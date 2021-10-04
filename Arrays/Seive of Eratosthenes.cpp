// Seive of Eratosthenes
// Checking all prime numbers between 0 to 1e9 in constant time i.e 1e9

#include <bits/stdc++.h>
using namespace std;

// Creating global variable cuz max size would be 1e9 then
vector<bool> prime(n + 1, true);

// Calculating function
// Concept is creating a boolean array and checking if its divisible by any number from i*i to n
void SieveOfEratosthenes(int n) {
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

// Driver Code
int32_t main() {
	int n;
	cin >> n;
	SieveOfEratosthenes(n);
	return 0;
}
