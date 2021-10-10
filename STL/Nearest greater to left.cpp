#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void display(vector<int> &v,int size)
{
    for(int i=0;i<=size-1;i++)
    {
        cout<<v[i]<<" ";
    }
}

int main()
{
vector<int>v;
stack<int>s;
int arr[5]={4,5,2,10,8};
int size=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<=size-1;i++)
{
    if(s.size()==0)
    {
        v.push_back(-1);
    }
    else if(s.size()>0 && s.top()>arr[i])
    {
        v.push_back(s.top());
    }
    else if(s.size()>0 && s.top()<=arr[i])
    {
        while(s.size()>0 && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.size()==0)
        {
            v.push_back(-1);
        }
        else{
            v.push_back(s.top());
        }
    }
    s.push(arr[i]);
    
}
display(v,size);
}
    


