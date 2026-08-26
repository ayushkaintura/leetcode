class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>need,have;
        for(int i = 0; i<ransomNote.length(); i++)
        {
            need[ransomNote[i]]++;
        }
         for(int i = 0; i<magazine.length(); i++)
        {
            have[magazine[i]]++;
        }
        for(auto &it : need)
        {
           char c=it.first;
           int fneed=it.second;
           int fhave=have[c];
           if(fhave< fneed)
           return false;
        }
        return true;
    }
};