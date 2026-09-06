class Solution {
public:
int func(vector<int> &arr,int n,int k,int guess){

    int count = 0;
    int bouquet = 0;
 for(int i = 0; i < arr.size(); i++)
{
            if(guess >= arr[i])
          {
            count++;
            if(count == k)
            {
                bouquet++;
                count = 0;
            }
          }else
          {
            count = 0;
          }
}
return bouquet;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
      int low = *min_element(bloomDay.begin(), bloomDay.end());
int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
       if ((long long)m * k > n)
    return -1;
        while(low <= high)
        {
            int guess=(high + low)/2;
            int res=func(bloomDay , n,k,guess);

            if(res >= m)
            {
                ans=guess;
                high = guess - 1;

            }
            else
            {
                low= guess+1;
            }
          
        }
        return ans;
    }
};