class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have ,need;
        string s="balloon";
        for(int i = 0; i < s.length(); i++){
            need[s[i]]++;
        }
        for(int  i = 0; i<text.length();i++)
        {
            have[text[i]]++;
        }
        int ans=INT_MAX;
        for(auto &it: need){
            char c= it.first;
                ans = min(ans,have[c]/need[c]);    
            }
        
        return ans;
    }
};