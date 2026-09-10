class Solution {
public:

bool help(vector<int> arr,int d,int n,long long guess)
{
  
    long long sum=0;
    long long ans=1;
    for(int i =0; i < n; i++)
    {
        sum+=arr[i];
        if(sum <= guess)
        {
           continue;
        }
        else
        {     ans++;
             sum=arr[i];
            
        }
    }
         if(ans <= d)
         {
            return true;
         }
         else
         {    
            return false;
         }
         
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long low = *max_element(weights.begin(),weights.end());
        long long high=0;
        long long ans=0;
        for(int i = 0; i < n; i++)
        {
                  high+=weights[i];
        }
              while(low <= high)
              {
                long long guess = low +(high -low)/2;
                long long res = help(weights,days,n,guess);

                if(res)
                {
                    ans=guess;
                    high=guess-1;
                }

                else
                {
                    low=guess+1;
                }
              }
              return ans;
    }
};