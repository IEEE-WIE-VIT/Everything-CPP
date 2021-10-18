#include<bits/stdc++.h>
using namespace std;

int solve (vector<long long> A) {
   int n = A.size();

long long sum = 0;

for(int i=0; i<n; i++)

{

    if(A[i] >= (pow(2,n))/2)

    {

         sum += A[i];

     }

}

return sum%1000000007;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        vector<long long> A(N);
        for(int i_A=0; i_A<N; i_A++)
        {
        	cin >> A[i_A];
        }

        int out_;
        out_ = solve(A);
        cout << out_;
        cout << "\n";
    }
}