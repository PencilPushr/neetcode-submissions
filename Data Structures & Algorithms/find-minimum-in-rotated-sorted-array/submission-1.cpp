class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int l = 0;
        int r = nums.size() - 1;
        int minimum = nums[0];

        //figure out rotation, as it can be rotated between 1 -> n times.

        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                minimum = std::min(minimum, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;

            minimum = std::min(minimum, nums[mid]);
            
            if (nums[mid] >= nums[l]) // search the right
            {
                l = mid + 1;
            }
            else // search the left
            {
                r = mid - 1;
            }
            
        }
        return minimum;
    }
};
