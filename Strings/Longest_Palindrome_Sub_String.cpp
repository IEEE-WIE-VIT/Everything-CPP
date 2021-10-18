#include <bits/stdc++.h>
using namespace std;
void LPSS(string s)
{
    int maxLength = 1;
    int start = 0;
    int n = s.size();
    int low, high;
    for (int i = 1; i < n; ++i)
    {
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < n && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        low = i - 1;
        high = i;
        while (low >= 0 && high < n && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    int end = start + maxLength - 1; 
    cout<<"Longest palindrome substring is ";
    for( int i = start; i <= end; ++i )
    {
        cout<<s[i];
    }
    cout<<endl;
    cout<<"Length of the longest palindrone substring is "<<maxLength<<endl;
}
 
int main()
{
    string s= "Hello World";
    LPSS(s);
    return 0;
}

