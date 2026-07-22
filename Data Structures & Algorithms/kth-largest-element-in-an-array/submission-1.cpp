class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        /*
            For a question like this; I ask another question:
             - What is stopping me from using a binary search tree ( Keeps ordering )
                1. Push into the bst ( log n )
                2. Iterate until size - k from the last? ( log n )
        */

        std::priority_queue< int > pq( nums.begin(), nums.end() );
        
        int result;
/*
        while( pq.size() - 1 > k )
        {
            result = pq.top();
            pq.pop();
        }
  */

        for( int i = 0; i < k - 1; ++i )
        {
            pq.pop();
        }

        return pq.top();
               
    }
};
