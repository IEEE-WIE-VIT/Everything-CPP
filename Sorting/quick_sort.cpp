//QUICK SORT

#include <iostream>
using namespace std;
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
// partition the array using last element as pivot
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
   
//quicksort algorithm
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pivot = partition(arr, low, high); 
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
} 
   
void displayArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<"  "; 
      
} 
   
int main() 
{ 
    int i, count; 
    cout<<"Enter the limit: "; 
    cin>>count; 
    int arr[count];
    cout<<"Enter the elements: "; 
    for(i=0;i<count;i++){ 
        cin>>arr[i];
    }
    cout<<endl<<"initial array: "<<endl;
    int n = sizeof(arr)/sizeof(arr[0]); 
    displayArray(arr,n);
    cout<<endl;
    quickSort(arr, 0, n-1); 
    cout<<endl<<"Array sorted with quick sort: "<<endl; 
    displayArray(arr,n); 
    return 0; 
}
