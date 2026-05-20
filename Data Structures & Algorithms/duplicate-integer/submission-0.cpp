class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> set;

        for (int i = 0; i < nums.size(); ++i) 
        {
            if (set.count(nums[i]) > 0)
            {
                return true;
            } 
            else 
            {
                set.insert(nums[i]);
            }
        }
        return false;
    }
};
