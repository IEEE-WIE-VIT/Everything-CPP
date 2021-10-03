#include <iostream>
using namespace std;
 
void KMP(string txt, string patt)
{
    int m = txt.length();
    int n = patt.length();
    if(m<n)
    {
    	cout<<"Pattern is not found in the text";
    	return;
	}
    if (n == 0)
    {
        cout << "The pattern occurs with shift 0";
        return;
    }
    int nxt[n + 1];
 
    for (int i = 0; i < n + 1; i++) {
        nxt[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int j = nxt[i + 1];
 
        while (j > 0 && patt[j] != patt[i]) {
            j = nxt[j];
        }
 
        if (j > 0 || patt[j] == patt[i]) {
            nxt[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < m; i++)
    {
        if (txt[i] == patt[j])
        {
            if (++j == n) {
                cout << "The pattern occurs in the text with " << i - j + 1<<" shift " << endl;
            }
        }
        else if (j > 0)
        {
            j = nxt[j];
            i--;  
        }
    }
}
int main()
{
    string text;
    cout<<"Enter the text for where pattern is to be searched:\n";
    getline(cin,text);
    string pattern;
    cout<<"Enter the pattern to be searched:\n";
    getline(cin,pattern);
 
    KMP(text, pattern);
 
    return 0;
}

