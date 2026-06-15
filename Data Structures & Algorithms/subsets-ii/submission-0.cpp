class Solution {
public:
/*

    So definitely requires a hashset/sorting, we are generating all possible subsets. Again closer to BDT.
    But n-ary just makes more sense for me.

    BDT tree:


    N-ary tree:
    x == don't take
                  []
                  /|\
        x    1        2         1
        |   /|\      /|\       /|\ 
        [] x x 2 1  x 1 x 1   x 1 2 x  // Here we would check before each iteration if a subset already existed. pruning if it has


        But I've solved permutations now and it seems like it is more hassle to keep a track, than sorting.
        By sorting we can just check previous != current   

        Additionally because of the style of how we solving, a bdt becomes harder to reason with rather than
        n-ary style


    So: [ 1, 2, 1 ] => [ 1, 1, 2 ]

    1. We are tracking subsets, so we always add the currently generating subset (see the decision tree above)
    at i == 0:
        - ( depth == 1 ) = { {} }       Then we pass i+1
        - 1 = { {}, 1 }
        - 2 = { {}, 1, { 1, 1 } }
        - 3 = { {}, 1, { 1, 1 }, { 1, 1, 2 } }... damn we need 1,2,1...
*/
    std::vector< std::vector< int >> g_result;

    /*
        std::unordered_map< int, int > g_freqmap; 
        I've decided against this, having solved permutations, a frequency map works, but tends to do more work
        than is necessary.
        Sorting seems to work just as well, just need to check 
    */

    void backtrack( 
        vector< int >& nums,
        vector< int >& curGen,
        int index
    )
    {
        g_result.push_back( curGen );

        for( int i = index; i < nums.size(); ++i )
        {
            if ( i > index && nums[ i ] == nums[ i - 1 ] ) continue; // Duplicate detected, cur is same as previous

            curGen.push_back( nums[ i ] );
            backtrack( nums, curGen, i + 1 );
            curGen.pop_back();
        }

        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        std::sort( nums.begin(), nums.end() );
        std::vector< int > curGen;
        backtrack( nums, curGen, 0 );
        return g_result;
    }

};
