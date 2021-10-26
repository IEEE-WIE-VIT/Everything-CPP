#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T>
class Algebra
{
public:
    static T gcd(T a,T b)
    {
        if(a==0)
            return b;
        return gcd(b % a, a);
    }
};

int main()
{
    int n1,n2;
    cout << "Enter Num1: ";
    cin>>n1;
    cout << "Enter Num2: ";
    cin>>n2;

    cout << Algebra<ll>::gcd(n1, n2) << endl;
}