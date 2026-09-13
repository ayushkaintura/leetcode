class Solution {
public:
bool help(vector<int>arr,int k,int n,long long guess)
{
    int count = 1;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum+arr[i] <= guess)
        {
            sum+=arr[i];
        }
        else
        {
            count++;
            sum=arr[i];
        }

    }
    if(count <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        long long low= *max_element(nums.begin(),nums.end());
        long long high = 0;
        long long res=0;
        for(int i = 0; i < n; i++)
        {
            high+=nums[i];
        }

        while(low <= high)
        {
            long long guess = low +(high - low)/2;

            long long ans = help(nums,k,n,guess);

            if(ans)
            {
                res=guess;
                high = guess-1;

            }
            else
            {
                low=guess+1;
            }
        }
        return res;

    }
};