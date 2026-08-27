class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;

        for(int i = 0; i < s.length(); i++)
        {
            f[s[i]]++;
        }
        int res=0;
bool odd =false;
        for(auto &it : f)
        {
            char c = it.first;
            if(it.second % 2==0)
            {
               res+=it.second;
            }
            else
            {
                res+=it.second-1;
                odd=true;
            }
        }
        if(odd==true)
        {
            res=res+1;
        }
        return res;
    }
};