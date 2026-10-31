class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> f1,f2;

        for(char ch : p)
        {
            f1[ch]++;
        }

        vector<int>res;

        int low=0;
        for(int  high =0; high < s.size(); high++)
        {
            f2[s[high]]++;
            while((high-low) +1 > p.size())
            {
                f2[s[low]]--;
                if(f2[s[low]]==0)
                {
                    f2.erase(s[low]);
                }
                low++;
            }

            if(high - low +1 == p.size())
            {
                if(f1==f2)
                {
                    res.push_back(low);
                }
            }


        }
        return res;
    }
};