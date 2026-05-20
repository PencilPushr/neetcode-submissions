class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        if (height.size() == 0)
        {
            return 0;
        }

        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);

        // Setup max left, iterate left to right
        maxLeft[0] = height[0];
        for (int i = 1; i < height.size(); i++)
        {
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }

        // Setup max right, iterate right to left.
        maxRight[height.size()-1] = height[height.size()-1];
        for (int i = height.size()-2; i >= 0; i--)
        {
            maxRight[i] = max(maxRight[i+1], height[i]);
        }

        // algorithm min(h[l], h[r]) - h[i]
        int ret = 0;
        for(int i = 0; i < height.size(); i++)
        {
            int cur = min(maxLeft[i], maxRight[i]) - height[i];
            if (cur <= 0) continue;
            ret += cur;
        }

        return ret;        
    }
};
