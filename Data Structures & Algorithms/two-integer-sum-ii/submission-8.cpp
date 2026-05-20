class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l, r;

        l = 0;
        r = numbers.size()-1;

        while (l < r)
        {
            int result = numbers[l] + numbers[r];
            if (result == target)
            {
                return {l+1,r+1};
            }
            else if (result > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }    
        return {0,1};
    }
};
