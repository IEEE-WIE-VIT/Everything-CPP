// CPP program to illustrate
// Implementation of erase() function
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> myvector{ 5,6,7,8,9 };
	vector<int>::iterator it1, it2;

	it1 = myvector.begin();
	it2 = myvector.end();
	it2--;
	it2--;

	myvector.erase(it1, it2);

	// Printing the Vector
	for (auto it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	return 0;
}
