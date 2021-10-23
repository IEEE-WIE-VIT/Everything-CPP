
class Solution {
  public:
    int romanToDecimal(string &str) {
        int a[26] = {0};
       a['I'-'A'] = 1;
       a['V'-'A'] = 5;
       a['X'-'A'] = 10;
       a['L'-'A'] = 50;
       a['C'-'A'] = 100;
       a['D'-'A'] = 500;
       a['M'-'A'] = 1000;
       int ans = a[str[0]-'A'];
       for(int i=1;i<str.length();i++){
           int x = a[str[i]-'A'];
           int y = a[str[i-1]-'A'];
           if(x<=y){
               ans+=x;
           }
           else{
               ans+=(x-(2*y));
           }
       }
       return ans;
    }
};