/*
    Given a array, find largest of each subarray of size k;
*/

#include<iostream>

using namespace std;

class basic{
    public:
        int* make_arr(int n);

        void disp_arr(int* arr,int n);
};

class solution:public basic{
    public:
        int* max_k(int* arr, int n, int k);
};

int main(){
    
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    solution sl;
    int* arr = sl.make_arr(n);

    int k;
    cout<<"Enter length of subarray: ";
    cin>>k;

    int* ans = sl.max_k(arr,n,k);

    sl.disp_arr(ans,n-k+1);

    delete []arr;
    delete []ans;
    return 0;
}

int* basic::make_arr(int n){
    int* arr = new int [n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    return arr;
}

void basic::disp_arr(int* arr , int n){
    for( int i = 0; i < n; ++i ){
        cout<<arr[i]<<" ";
    }
    return ;
}

int* solution::max_k(int* nums, int n, int k){

    int * window = new int [k];

    int * ans = new int [n - k + 1];

    int front = 0 , end = -1 , size = 0;
    for(int i = 0 ; i < k ; ++i){
        
        while(size > 0 && nums[window[end]] <= nums[i]){
            size--;
            end--;
        }
        
        end = (end + 1)%k;
        size++;
        
        window[end] = i;
    }
    ans[0] = nums[window[front]];
    
    for(int i = k ; i < n ; ++i){
        
        while(size > 0 && window[front] <= i - k){
            front = (front + 1)%k;
        	size--;
        }
        
        while(size > 0 && nums[window[end]] <= nums[i]){
            end = (end - 1 + k)%k;
            size--;
        }
        
        end = (end + 1)%k;
        window[end] = i;
        size++;
        
        ans[i - k + 1] = nums[window[front]];
    }
    
    
    delete []window;
    return ans;
}