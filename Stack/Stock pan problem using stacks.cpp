// 1st Approach

#include <iostream> 
using namespace std;  
vector<int> fill_span(int price[],int n){
    vector<int>span_arr(n);
    span_arr[0] = 1;
    int span = 1;
    for(int i=1;i<n;i++){
        span = 1;
        for(int j=i-1;j>=0;j--){
            if(price[j]<=price[i]){
                span++;
            }
            else
                break;
        }
        span_arr[i] = span;
    }
    return span_arr;
}
int main()  
{  
    int price[] = { 10, 4, 5, 90, 120, 80 };  
    int n = sizeof(price) / sizeof(price[0]);  
    vector<int>span = fill_span(price, n);  
    for(int i=0;i<n;i++){
        cout << span[i] <<" ";
    }
  
    return 0;  
}



//2nd Approach

#include <bits/stdc++.h> 
using namespace std;  
vector<int> fill_span(int price[], int n)
{
   vector<int>v(n);
   stack<int>s;
   s.push(0);
   v[0]=1;
   for(int i=1;i<n;i++){
       while(s.empty()!=true && price[i]>=price[s.top()]){
           s.pop();
       }
       if(s.empty()==true){
           v[i] = i+1;
       }
       else{
            v[i] = i-s.top();
       }
       s.push(i);
   }
   return v;
}
int main()  
{  
    int price[] = { 10, 4, 5, 90, 120, 80 };  
    int n = sizeof(price) / sizeof(price[0]);  
    vector<int>span = fill_span(price, n);  
    for(int i=0;i<n;i++){
        cout << span[i] <<" ";
    }
  
    return 0;  
}


