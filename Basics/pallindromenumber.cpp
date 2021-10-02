#include <iostream>  
using namespace std;  
int main()  
{  
  int n,f,sum=0,temp;    
  cout<<"Enter the Number=";    
  cin>>n;    
 temp=n;    
 while(n>0)    
{    
 f=n%10;    
 sum=(sum*10)+f;    
 n=n/10;    
}    
if(temp==sum)    
cout<<"Number is Palindrome.";    
else    
cout<<"Number is not Palindrome.";   
  return 0;  
}  