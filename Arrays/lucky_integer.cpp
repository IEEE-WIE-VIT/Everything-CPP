// Constraints:
// 1 <= arr.length <= 500
// 1 <= arr[i] <= 500
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin>>n ;
     vector<int>arr(n,0);
     for(int i = 0 ;i<n;i++){
         cin>>arr[i];
     }
     vector<int>farr(501,0);
     for(int val : arr){
         farr[val]++ ;
     }
     int Max = -1 ;
     for(int i = 1 ;i<501;i++){
         if(farr[i]==i){
             Max = max(farr[i],Max);
         }
     }
     cout<<Max ;
    return 0;
}