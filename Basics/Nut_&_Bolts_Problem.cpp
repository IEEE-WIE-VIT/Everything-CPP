#include <iostream>
using namespace std;
int partition(int *arr,int s,int e){
//partition function to make two parts of the array placing the pivot element in its correct position
	int i = s-1;
	for(int j = s;j<e;j++){
		if(arr[j]<arr[e])
			{
				i = i+1;
				swap(arr[i],arr[j]);
			}
	}
	swap(arr[i+1],arr[e]);
	return i+1;
}
void quicksort(int *arr,int s,int e){
	if(s<e){ //checking if the s,e are in bounds		
		int p = partition(arr,s,e);
		cout<<p<<endl;
		quicksort(arr,s,p-1);
		quicksort(arr,p+1,e);
	}
}
void print(int arr[],int n){
	for(int i = 0;i<n;i++)
		cout<<arr[i]<<" ";
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i = 0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n-1);
	print(arr,n);
	return 0;
}
