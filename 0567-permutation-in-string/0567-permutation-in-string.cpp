class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char, int> m1, m2;  
        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i]]++;
        }

        int low = 0;

        for (int high = 0; high < s2.size(); high++) {

            
            m2[s2[high]]++;
            
            int windowSize = high - low + 1;  
            if (windowSize > s1.size()) {

                m2[s2[low]]--;

                if (m2[s2[low]] == 0) {
                    m2.erase(s2[low]);
                }

                low++;
            }
 
            if (m1 == m2) {
                return true;
            }
        }

        return false;
    }
};