#include <iostream>
using namespace std;
int main()
{
int n, s, x, y;
cout << "Enter number of rows to show star pattern: ";
cin >> n;
for(x = 1; x <= n; x++)
{
for(s = x; s < n; s++)
cout << " ";
for(y = 1; y <= x; y++)
cout << "* ";
cout << "\n";
}
return 0;
}
