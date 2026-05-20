class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> seen(nums.begin(), nums.end());

        int longest = 0;
        for (int cur : seen )
        {
            if (seen.find(cur - 1) == seen.end())
            {
                int length = 1;
                while ( seen.find(cur + length ) != seen.end() )
                {
                    length++;
                }
                longest = std::max(longest, length);
            }
        }
        return longest;
    }
};
