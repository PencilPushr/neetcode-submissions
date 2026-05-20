class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow = 0;
        int fast = 0;

        // Find the start of the loop
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        int slow2 = 0;
        while (true)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2)
                break;
        }
        return slow;
    }
};
