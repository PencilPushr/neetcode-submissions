class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int l = 0;
        int r = heights.size() - 1;

        int cur_max = 0;
        while (l < r)
        {
            int area = (r - l) * std::min(heights[l], heights[r]);
            cur_max = std::max(cur_max, area);

            if (heights[l] > heights[r])
            {
                r--;
            }
            else
            {
                l++;
            }
            // Edge case, check if left[i+1] or right[i-1] is greater in height
        }
        return cur_max;
    }
};
