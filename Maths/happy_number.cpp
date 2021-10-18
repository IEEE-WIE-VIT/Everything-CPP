#include <iostream>
#include <cmath>
using namespace std;
int getSum(int n){
        int sum = 0 ;
        while(n>0){
            sum += (n%10)*(n%10);
            n /= 10 ;
        }
        return sum ;
}
int main()
{
    int n ;
    cin >> n;
    int length = (int)log10(n);
        while(length>=1){
            n = getSum(n);
            length = (int)log10(n);
        }
        if(n==1 || n==7){
            cout<<"true"<<endl ;
        }
        else {
            cout<<"false"<<endl ;
        }
    return 0;
}

