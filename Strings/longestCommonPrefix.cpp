string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    string ans = "";
    int i = 0;
    while(A[0][i]==A[n-1][i] && i<n){
        ans = ans + A[0][i];
        i++;
    }
    return ans;
}
