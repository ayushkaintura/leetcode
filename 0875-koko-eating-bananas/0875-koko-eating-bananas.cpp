class Solution {
public:

long long  func(vector<int> &arr,int n,int speed)
{
   long long h=0;
    for(int i = 0;i < n; i++)
    {
        h= h+arr[i]/speed;
        if(arr[i]%speed!=0){
        h++;
        }
    }
    return h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        int low=1;
        int res=-1;

        while(low <= high )
        {
            int guess = (high+low)/2;

            long long hours=func(piles,n,guess);
            if(hours > h)
            {
                low=guess+1;
            }
            else
            {
                res=guess;
                high=guess-1;
            }

        }
        return res;
    }
};