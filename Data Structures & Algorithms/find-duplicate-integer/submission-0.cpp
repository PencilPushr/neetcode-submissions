class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow = 0;
        int fast = 0;

        // Find the duplicate (a.k.a. the cycle)
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        }

        // Increment the two pointers till you find the start of the cycle
        // Think of p and x gaps decreasing as you approach the intersection
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
