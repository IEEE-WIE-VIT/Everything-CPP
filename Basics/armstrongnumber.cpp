#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
   int i,num,j,n,arm=0;
   cout<<"Enter the number\n";
   cin>>n;
   num=n;
   while(n!=0)
   {
      j=n%10;
      arm=j*j*j+arm;
      n=n/10;
   }
   if(num==arm)
   {
      cout<<"The given number is armstrong number";
   }
   else{
      cout<<"Not an armstrong number";
      getch();
   } 
}