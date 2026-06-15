class Solution {
public:

/*
    Based on previous experience with trees, I'm assuming this can be solved iteratvely as well as recursively

    But for learning purposes I assume recursive is easiest.

                   []
               /       \
        skip 1          take 1
            []            [1]
          /    \        /     \
    skip 2   take 2  skip 2   take 2
       []       [2]   [1]      [1][2]

    remember
        return value is what we propagate back up, usually through post order. 
            But we have a global/local reference which acts like a global - maybe look at other tree problms like this (level order traversal) 
        function args are what we bring down to the next state

        globals can be both but keeping them in their respective areas makes it more obvious.
        I personally like the clarity of having a global, less mental clobber

        A Good mental model to have is that in particular if we do a binary decision tree:
         - left is do no take
         - right is we take
         So if we do an in order traversal, we will fill out the tree:
        
        backtrack(index):
            if index == nums.size():
                save current subset
                return

            skip nums[index]
            take nums[index]
*/

    std::vector<std::vector< int >> g_Result;
    static constexpr bool BDT_ = false;

    void backtrack( std::vector<int>& nums, std::vector< int >& combination, int index )
    {
        if constexpr ( BDT_ )
        {
            // Base case - add to our final result
            if ( index == nums.size() )
            {
                g_Result.push_back( combination );
                return;
            }

            // Take the left subtree ( skip stuff ) - do nothing, no push and pop
            backtrack( nums, combination, index + 1 );

            // push our current node ( in order )
            // Take right subtree - keep adding
            combination.push_back( nums[index] );
            backtrack( nums, combination, index + 1 );

            // clear decisions
            combination.pop_back();
        }
        else // N-Ary style
        {
            g_Result.push_back( combination );

            for( int i = index; i < nums.size(); ++i )
            {
                combination.push_back( nums[ i ] );
                backtrack( nums, combination, i + 1 );
                combination.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector< int > combination;
        backtrack( nums, combination, 0 );
        return g_Result;
    }
};
