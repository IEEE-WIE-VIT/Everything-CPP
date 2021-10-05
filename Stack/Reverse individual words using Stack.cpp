#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s="codespeedy";
    int n=s.length();

    cout<<"Given string - \n";
    cout<<s<<"\n";

    stack<int> p;  // empty stack
    for(int x=0; x<n; x++){     
        p.push(s[x]);
    }
    s="";  // empty string

    for(int x=0; x<n; x++){
        s+=p.top();
        p.pop();
    }

    cout<<"Inverted String - \n";
    cout<<s<<"\n";

    return 0;
}