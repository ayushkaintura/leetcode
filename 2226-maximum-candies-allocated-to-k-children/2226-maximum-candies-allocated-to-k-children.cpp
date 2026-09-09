class Solution {
public:
bool help(vector<int> & arr,long long k,int n,long long guess)
{    long long  count=0;
    for(int i = 0;i < n; i++)
    {
        if(arr[i]%guess==0)
        {
         count += arr[i] / guess;  
        }
        else if(arr[i]>=guess)
        {
          count += arr[i] / guess;
        }
    }
    if(count >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        
        
        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());
        long long ans=0;
        while(low <= high)
        {
            long long guess= low +(high-low)/2;

            bool res=help(candies,k,n,guess);
            if(res)
            {
                ans=guess;
                low=guess+1;
            }
            else
            {
                high = guess-1;
            }
        }
        return ans;
    }
};