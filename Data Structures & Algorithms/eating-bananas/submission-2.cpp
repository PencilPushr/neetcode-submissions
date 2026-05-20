class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        // array to highest number
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()); // get value from forward iterator
        int res = r; // worst case the result is the maximum element

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            int time = 0;
            for (int pile : piles) // loop through the array, checking if we can eat all the piles in the time given
            {
                time += (pile - 1) / mid + 1;
            }

            if (time <= h)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return res;
    }
};
