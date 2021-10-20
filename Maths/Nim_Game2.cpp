#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
 
    int x = 0;
    for(int &e : a)
    {
        cin >> e;
        e = e % 4;
        x ^= e;
    }
    if(x == 0)
        cout << "second\n";
    else 
        cout << "first\n";         
}

// There are n heaps of sticks and two players who move alternately. On each move, a player chooses a non-empty heap and removes 1, 2, or 3 sticks. The player who removes the last stick wins the game.
// Your task is to find out who wins if both players play optimally.

// Input:

// The first input line contains an integer t: the number of tests. After this, t test cases are described:
// The first line contains an integer n: the number of heaps.
// The next line has n integers x1,x2,…,xn: the number of sticks in each heap.

// Output:
// For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.