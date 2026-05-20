class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        if (height.empty()) return 0;
        int l, r;
        int maxLeft, maxRight;
        int res;

        l = 0;
        r = height.size()-1; 
        maxLeft = height[l];
        maxRight = height[r];

        res = 0;
        while (l < r)
        {
            if (maxLeft < maxRight)
            {
                l++;
                maxLeft = max(maxLeft, height[l]);
                res += maxLeft - height[l];
            }
            else
            {
                r--;
                maxRight = max(maxRight, height[r]);
                res += maxRight - height[r];
            }
        }

        return res;
    }
};
