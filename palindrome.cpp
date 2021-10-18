#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

stack<string>st;

void SubSeq(string s,string ans)
{
    int n=s.size();
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
           {
             st.push(s.substr(i, len)) ;
           }

}


stack<string>FindPalindrome(stack<string>st)
{
        stack<string>Ans;
        string s=st.top();

        while(!st.empty())
        {
            s=st.top();
            st.pop();
        stack<char>st2;
        queue<char>q;
        int flag=1;

        for(int i=0;i<s.size();i++)
        {
           st2.push(s[i]);
           q.push(s[i]);
        }

        while(!st2.empty() and !q.empty())
        {
           if(st2.top()!=q.front())
           {
              flag=0;
              break;
           }
           st2.pop();
           q.pop();
        }
        if(flag!=0)
            Ans.push(s);


    }
    return Ans;

}


int main()
{
    string str;
    cout<<"Enter Your String: ";
    getline(cin,str);
    SubSeq(str,"");

    cout<<endl<<"Palindromic Strings are: ";

    stack<string>Ans= FindPalindrome(st);

    while(!Ans.empty())
    {
        cout<<Ans.top()<<" ";
        Ans.pop();
    }

}
