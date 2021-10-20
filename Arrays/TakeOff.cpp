#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,p,q,r;
        cin>>n>>p>>q>>r;
        int count=0;
        for(int i=1; i<=n; i++){
            int num=0;
            if(i%p==0)num++;
            if(i%q==0)num++;
            if(i%r==0)num++;
            if(num==1){
                count++;
            }
        }
        cout<<count<<endl;
    }
}