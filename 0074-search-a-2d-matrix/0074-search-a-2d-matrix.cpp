class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=  matrix[0].size();

        int low= 0 ;
        int high  =  (r*c)-1;

        while( low <= high)
        {
            int guess= low+ (high-low)/2;
            int row = guess/c;
            int col =guess%c;

            if(matrix[row][col] == target)
            return true;

            if(matrix[row][col] < target)
            {
                low=guess+1;
            }
            else
            {
                high = guess-1;
            }
        }
        return false;
    }
};