#include<iostream>
using namespace std;
void linearSearch(int a[],int n)
{
    //int size;
    int temp=-1;
    for(int i=0;i<5;i++)
    {
        if (a[i]==n)
        {
            cout<<"element found at position: "<<i+1<<endl;
            temp=0;
            
        }
      
    }
    if(temp==-1)
    {
      cout<<"element not found";  
    } 
    
}
int main()
{
    int size;
    //cin>>size;
    int arr[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    int num;
    cout<<"enter the element to be searched";
    cin>>num;
    linearSearch(arr,num);
    return 0;
}
