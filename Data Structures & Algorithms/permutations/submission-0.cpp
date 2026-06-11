class Solution {
public:

/*
    For permutations, order doesn't matter, we just want to try every possible variation
    
    We can keep a track of have we used this number before

    we can try every perm like so:

                []
            /    |    \
          1      2      3
      /  |   \    
     x   2    3
       / | \   / | \ 
       x x  3  x 2  x
        
    If we have seen it already in the hashmap we just continue to the next number.
*/

    std::vector< std::vector< int >> g_result;

    void backtrack( 
        std::vector< int >& nums, 
        std::vector< int >& curGen, 
        std::unordered_set< int >& used 
    )
    {
        if ( curGen.size() == nums.size() )
        {
            g_result.push_back( curGen );
            return;
        }

        for( int i = 0; i < nums.size(); ++i )
        {
            // If seen this number before (unique) ( This would probbaly change if we were allowed duplicates )
            if ( used.find( nums[ i ] ) != used.end() ) continue;
            used.insert( nums[ i ] );
            curGen.push_back( nums[ i ] );

            backtrack( nums, curGen, used );
            
            used.erase( nums[ i ] );
            curGen.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        std::unordered_set< int > used;
        std::vector< int > curGen;

        backtrack( nums, curGen, used );

        return g_result;
    }
};
