#include <iostream>
using namespace std;

int binary(int a[], int n, int k) {
    int res = 0;
    int mid;
    int left = 0;
    int right = n;
    while (left <= right && ! res) {
        mid = (left + right) / 2;
        if (a[mid] < k) {
            left = mid + 1;
        }
        else if (a[mid] > k) {
            right = mid - 1;
        }
        else {
            res = mid;
        }
    }
    if (! res) {
            res=-1;
        }
    return res;
}

int main() {
    int n,i,k;
     cout << "Enter limit: ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
     cout << "\nEnter no to find: ";
    cin>>k;
    int result = binary(a, n ,k);
    if(result==-1){
         cout<<"not found";
    }
    else{
        cout<<"Found";
    cout <<"\nposition: " <<result;
    }
}
