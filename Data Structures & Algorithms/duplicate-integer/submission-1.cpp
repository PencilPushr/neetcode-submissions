class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> bucket;

        for(int i = 0; i < nums.size(); i++)
        {
            if (bucket.count(nums[i]) > 0) return true;
            bucket.insert(nums[i]);
        }
        
        return false;
    }
};
