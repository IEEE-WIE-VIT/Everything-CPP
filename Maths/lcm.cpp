#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll hcf(ll a, ll b)
{
    if (b == 0)
        return a;
    return hcf(b, a % b);
}

ll lcm(ll arr[], int n)
{
    ll ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = ((arr[i] * ans) / (hcf(arr[i], ans)));
    }
    return ans;
}

int main()
{
    ll arr[] = {7,14 , 21, 7, 49};
    cout << lcm(arr, 5) << endl;
}