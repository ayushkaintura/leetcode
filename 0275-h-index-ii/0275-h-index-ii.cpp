class Solution {
public:
bool help(vector<int> &arr,int n,int guess)
{
    int count  = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= guess)
        {
            count++;
        }
    }
        if(count >= guess)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low=0;
        int high = n;
         int ans=0;
        while(low <=  high)
        {
            int guess= (high + low)/2;

          bool res=help(citations,n,guess);
            if(res)
            {
                ans=guess;
                low=guess+1;
            }
            else
            {
                high=guess-1;
            }
        }
        return ans;
    }
};