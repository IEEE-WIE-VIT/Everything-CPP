int countRev (string s)
{
    int len = s.length();
   

    if (len % 2 != 0) {
        return -1;
    }
    int left = 0, right = 0;
    int ans;
    for (int i = 0; i < len; i++) {

        if (s[i] == '{') {
            left++;
        }
       

        else {
            if (left == 0) {
                right++;
            }
            else {
                left--;
            }
        }
    }
    ans = ceil(left / 2.0) + ceil(right / 2.0);
    return ans;
}