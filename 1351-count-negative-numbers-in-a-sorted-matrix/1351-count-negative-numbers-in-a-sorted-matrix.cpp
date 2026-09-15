class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
     int r =grid.size();
     int c = grid[0].size();
int ans=0;
for(int i = 0; i < r; i++)
{
     int low=0;
     int high =c-1;
   

        while(low <= high)
        {
            int guess = low +(high -low)/2;
            if(grid[i][guess]< 0)
            {
                
                high = guess-1;
            }
            else
            {
                low=guess+1;
            }
        }
        ans+=c-low;   // 4  3  2 -1 -2
                               // ↑
                              //low = 3
}
        return ans;
    }
};