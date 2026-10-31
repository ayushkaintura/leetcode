class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(256, 0);

        int low = 0;
        int res = 0;
        int maxcount = 0;

        for(int high = 0; high < s.size(); high++)
        {
            arr[s[high]]++;

            maxcount = max(maxcount, arr[s[high]]);
        

            while((high-low+1) - maxcount > k)
            {
                arr[s[low]]--;
                low++;
            }

            res = max(res, high-low+1);
        }

        return res;
    }
};