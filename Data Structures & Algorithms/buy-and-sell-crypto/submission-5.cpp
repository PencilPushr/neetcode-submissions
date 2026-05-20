class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int l = 0, r = 1;
        int maxProfit = 0;

        while (r < prices.size())
        {
            maxProfit = max(maxProfit, prices[r] - prices[l]);
            if (prices[l] > prices[r])
            {
                l = r;
            }
            r++;
        }

        return maxProfit;
    }
};
