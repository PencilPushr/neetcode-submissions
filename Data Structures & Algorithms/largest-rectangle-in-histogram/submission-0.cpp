class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        using index = int;
        using height = int;

        int maxArea = 0;
        std::stack<std::pair<index, height>> stack;

        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i])
            {
                std::pair<index, height> top = stack.top();
                maxArea = std::max(maxArea, (top.second * (i - top.first)));
                start = top.first;
                stack.pop();
            }
            stack.push({start, heights[i]});
        }        

        while (!stack.empty())
        {
            std::pair<index, height> top = stack.top();
            maxArea = std::max(maxArea, (top.second * ((int)heights.size() - top.first)));
            stack.pop();
        }

        return maxArea;
    }
};
