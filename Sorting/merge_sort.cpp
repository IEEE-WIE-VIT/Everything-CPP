#include<iostream>
using namespace std;

void merge(string &a,int low,int mid,int high)
{
 string b;
 int i,j,m;
 j=mid+1;
 m=low;
 for(i = low; m<=mid && j<=high; i++)
 {
 if(a[m]<=a[j])
 {
 b[i] = a[m];
 m++;
 }
 else
 {
 b[i] = a[j];
 j++;
 }
 }
 while(m<=mid)
 {
 b[i] = a[m];
 i++;
 m++;
 }
 while(j<=high)
 {
 b[i] = a[j];
 i++;
 j++;
 }
 for(i=low; i<=high;i++)
 a[i] = b[i];
}
void merge_sort(string &a,int low,int high)
{
 if(low<high)
 {
 int mid=(low+high)/2;
 merge_sort(a,low,mid);
 merge_sort(a,mid+1,high);
 merge(a,low,mid,high);
 }
}

int main()
{
 string a;
 int n,i,j;
 cout<<"Enter the string:";
cin>>a;
 n=a.length();
 merge_sort(a,0,n);
 cout<<"sorted string:";
 for(i=0;i<=n;i++)
 cout<<a[i]<<" ";
 return 0;
}
