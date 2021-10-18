#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=1;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int j=0;
    while(j<n-1){
        if(arr[j]>arr[j+1]){
            count++;
            j++;
        }
        else{
            j++;
        }
    }
    cout<<count<<endl;
}