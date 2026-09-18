class Solution {
public:
int help(vector<vector<int>> &arr,int n,int m,int guess)
{
     int r = n-1;
     int c = 0;
    long long count = 0 ;
    
        while(r >=0  && c < m){
    
    if(arr[r][c] <= guess)
    {
        count += r+1;
        c++;
    }else
    {
        r--;
    }
        }
    return count;
    
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low=matrix[0][0];
        int high = matrix[n-1][m-1];
  int res = 0;
        while(low <= high){
            int guess= low+(high-low)/2;

            int ans = help(matrix,n,m,guess);
            if(ans >= k)
            {
                res = guess;
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