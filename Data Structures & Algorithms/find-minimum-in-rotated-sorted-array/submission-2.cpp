class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int l = 0;
        int r = nums.size() - 1;
        int res = 0;

        if (nums[l] <= nums[r])
        {
            return nums[l];
        }

        while (l < r) 
        {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[r]) 
            {
                // Minimum is in the right half
                l = m + 1;
            } 
            else 
            {
                // Minimum is in the left half (including m)
                r = m;
            }
        }
        return nums[l];
    }
};
