#include <iostream>

using namespace std;

int main()
{
    int n,q;
    cin>>n;
    string strings;
    for(int i=0;i<n;i++) cin>>strings[i];
    cin>>q;
    string queries;
    for(int i=0;i<q;i++) cin>>queries[i];
    for(int i=0;i<q;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(strings[j]==queries[i]){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
