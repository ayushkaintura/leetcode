class Solution {
public:

struct cmp
{
     bool operator()(pair<int,int>&a,pair<int,int>&b)
     {
        if(a.first!=b.first)
        {
            return a.first> b.first;
        }
        return a.second  >  b.second;
     }

};
  
    vector<int> topKFrequent(vector<int>& nums, int k) {
                        unordered_map<int,int>mp;

                        for(int i = 0 ; i < nums.size(); i++)
                        {
                            mp[nums[i]]++;
                        }      

                        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

                    for(auto it : mp)
                    {
                        int element = it.first;
                        int freq = it.second;
                        pair<int,int > curr = {freq,element};

                        if(pq.size()  < k)
                        {
                            pq.push(curr);
                            continue;
                        }

                        if(curr.first < pq.top().first)
                         continue;
                        
                        pq.pop();
                        pq.push(curr);

                    }
         vector<int>res;
                    while(!pq.empty())
                    {
                         res.push_back(pq.top().second);
                         pq.pop();
                    }
                    return res;
    }
};