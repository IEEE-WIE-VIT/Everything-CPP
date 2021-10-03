#include<iostream>
using namespace std;
void merge(int [], int [], int, int);

int main()
{
        int arr1[100], arr2[100], arr3[100], a1, a2, i, j, k;

        cout<<"\n Enter Number of elements in 1st Array: ";
        cin>>a1;

        cout<<"\n Enter the elemnts of First Array in a sorted manner : \n";
        for (i = 0; i < a1; i++)
        {
                cout<<" ";
                cin>>arr1[i];
        }
        cout<<"\n Enter Number of elements in 2nd Array: ";
        cin>>a2;

        cout<<"\n Enter the elemnts of Second Array in a sorted manner : \n";
        for (i = 0; i < a2; i++)
        {
                cout<<" ";
                cin>>arr2[i];
        }
        merge(arr1, arr2, a1, a2);
        i = 0;
        j = 0;
        while (i < a1 && j < a2)
        {
                if (arr1[i] < arr2[j])
                {
                        arr3[k] = arr1[i];
                        i++;
                }
                else
                {
                        arr3[k] = arr2[j];
                        j++;
                }
                k++;
        }
        if (i >= a1)
        {
                while (j < a2)
                {
                        arr3[k] = arr2[j];
                        j++;
                        k++;
                }
        }
        if (j >= a2)
        {
                while (i < a1)
                {
                        arr3[k] = arr1[i];
                        i++;
                        k++;
                }
        }
        cout<<"\n\n Sorted Array After Merging : \n";
        for (i = 0; i < a1 + a2; i++)
        {
                cout<<" ";
                cout<<arr3[i];
        }
        return 0;
}
void merge(int arr1[], int arr2[], int a1, int a2)
{
        for (int i=a2-1; i>=0; i--)
        {
                int j, last = arr1[a1-1];
                for (j=a1-1; j >= 0 && arr1[j] > arr2[i]; j--)
                        arr1[j+1] = arr1[j];
                if (j != a1-1)
                {
                        arr1[j+1] = arr2[i];
                        arr2[i] = last;
                }
        }
}


