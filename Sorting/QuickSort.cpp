// Quick Sort program in C++

#include <iostream>
using namespace std;

void printArr(int temp[], int n) {
  int i;
  for (i = 0; i < n; i++)
    cout << temp[i] << " ";
  cout << endl;
}

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

// Partition Function 
int partition(int array[], int start, int end) {
    
  int pivot = array[end];
  int i = (start - 1);

  for (int j = start; j < end; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  
  swap(&array[i + 1], &array[end]);
  return (i + 1);
}

// QuickSort Function
void Quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    Quicksort(arr, low, pi - 1);
    Quicksort(arr, pi + 1, high);
  }
}

// Main Program
int main() {
  int data[] = {78, 5, 18, 56, 4, 26, 10, 67, 13};
  int n = sizeof(data) / sizeof(data[0]);
  cout<<"==============================\n"<<endl;
  cout<<"Quick Sort Program in CPP for Array's \n"<<endl;
  cout<<"=============================="<<endl;
  cout << "\n->The Unsorted Array is:-\n";
  printArr(data, n);
  
  Quicksort(data, 0, n - 1);
  
  cout << "\n->The Array after quick sort is:- \n";
  printArr(data, n);
}

/* 

Output for the Quick Sort Program:-
==============================

Quick Sort Program in CPP for Array's

==============================

->The Unsorted Array is:-
78 5 18 56 4 26 10 67 13

->The Array after quick sort is:-
4 5 10 13 18 26 56 67 78

*/