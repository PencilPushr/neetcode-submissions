class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n = numbers.size();
        int lhs = 0;
        int rhs = numbers.size()-1;

        while ( lhs < rhs)
        {
            int cursum = numbers[lhs]+numbers[rhs];
            if (cursum == target)
            {
                return {lhs +1, rhs +1};
            }

            if (cursum > target)
            {
                rhs--;
            }

            if (cursum < target)
            {
                lhs++;
            }
        }

        return {};
    }
};
