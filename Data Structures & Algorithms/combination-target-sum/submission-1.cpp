class Solution {
public:
/*
    Unlike Subsets problem, I'm not sure we can use a decision tree, or if we did would it work?
    perhaps you build up a decision tree but with like two sum, if index is 2, -> recurse and check 
    if numbers are ==9, if <9 recurse pick another number, if > 9 reject, if difference is not in the array reject
*/

    std::vector< std::vector< int >> g_result;

    void backtrack( std::vector< int >& nums, int target, std::vector< int >& curGen, int start )
    {
        int sum = std::reduce( curGen.begin(), curGen.end() );

        // We have target!
        if ( sum == target )
        {
            g_result.push_back( curGen );
            return;
        }

        // If we overshot or no amount of adding with let us reach target - empty branch 
        int difference = sum - target;
        if ( sum > target )
            return;

        // Maybe BDT works? - but this might require using an index? nvm we are using start which is index
        
        // Try N-ary
        //for( int i = start; i < )

        // bdt
        // No take branch (left)
        //backtrack( nums, target, curGen, start + 1);
        // nevermind I'm not sure how it would work, would we find the maximum before the diff we calculated
        // and only use up till that array?

        // Back to n-array style
        for( int i = start; i < nums.size(); ++i )
        {
            // try every combo and keep adding (bases cases above should handle empty inserts)
            curGen.push_back( nums[ i ] );
            backtrack( nums, target, curGen, i );
            curGen.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        std::vector< int > curGen;
        backtrack( nums, target, curGen, 0 );
        return g_result;
    }
};
