class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int iXorRes = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            iXorRes ^= nums[i];
        }

        return iXorRes;
    }
};
