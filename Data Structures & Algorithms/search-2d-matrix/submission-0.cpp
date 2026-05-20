class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0;
    int r = m * n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;  // Calculate the middle index
        int row = mid / n;  // Use 'mid' instead of 'm'
        int col = mid % n;  // Use 'mid' instead of 'm'
        int cur = matrix[row][col];

        if (cur == target)
        {
            return true;
        }
        else if (cur < target)
        {
            l = mid + 1;  // Use 'mid' instead of 'm'
        }
        else 
        {
            r = mid - 1;  // Use 'mid' instead of 'm'
        }
    }
    return false;
    }
};
