// Tower of Hanoi problem in C++ to solve recursion problem
#include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int num_disks, char transfer_rod,
					char receiver_rod, char intermediate_rod) {
	if (num_disks == 1) {
		cout << "Move disk one from transfer rod " << transfer_rod <<
							" to receiver rod " << receiver_rod<<endl;
		return;
	}
	
	TowerOfHanoi(num_disks - 1, transfer_rod, intermediate_rod, receiver_rod);
	cout << "Move disk " << num_disks << " from transfer rod " << transfer_rod <<
								" to receiver rod " << receiver_rod << endl;
	TowerOfHanoi(num_disks - 1, intermediate_rod, receiver_rod, transfer_rod);
}

// Driver code
int main() {
	int num_disks = 4; // Number of disks given
	TowerOfHanoi(num_disks, '1', '2', '3'); // 1, 2 and 2 are names of rods to which we have to put the disks
	return 0;
}

// This code is contributed by Tisha
