class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<pair<int, int>> stack; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++)
        {
            int t = temperatures[i]; // Current day temp
            // while the current temp is greater than the top
            while (!stack.empty() && t > stack.top().first)
            {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second; // Get the difference
            }
            stack.push({t, i});
        }
        return res;   
    }
};
