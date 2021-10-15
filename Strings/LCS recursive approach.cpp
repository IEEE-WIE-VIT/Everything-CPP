class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return recursive(text1,text2,0,0);
    }
    int recursive(string text1,string text2, int i, int j)
    {
        if(i>=text1.length() || j>=text2.length())
        {
            return 0;
        }
        if(text1[i]==text2[j])
        {
            return 1+recursive(text1, text2, i+1,j+1);
        }
        else{
            return std::max(
            recursive(text1,text2,i+1,j),
            recursive(text1,text2,i,j+1));
        }
    }
};
