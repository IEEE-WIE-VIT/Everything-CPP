#include<iostream>
using namespace std;

int IsOperator(char x)
{
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return 1;
  }
  return 0;
}


int main()
{
    string s,c="";
    cout<<"Enter the Postfix Expression: "<<endl;
    cin>>s;
    stack<char> st;
    cout<<"The Prefix expression is: "<<endl;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(IsOperator(s[i]))
        st.push(s[i]);
        else{
            c+=s[i];
            while(!st.empty() && st.top()=='#')
            {
                st.pop();
                c+=st.top();st.pop();
            }
            st.push('#');
        }
    }
    reverse(c.begin(),c.end());
    cout<<c;
}