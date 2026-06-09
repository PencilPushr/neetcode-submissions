class Solution {
public:
/*
    use a map to keep a track of letters allowed.
    OR use a array[26] = seenInArray;

    This I feel like naturally goes towards bdt

    ---- We don't need this - 6 days later

    We can simply keep a track of all the previously used ones with a - ah, nevermind 
    we will likely need to keep a track of the numbers allowed and then decrement them, if it's < 0 then we return 

    but because of the nature of trying it does seem like a bdt would work better but coming back to this problem
    it looks like we would need to sort it in order for that strategy to be viable.

    So currently two strategies:
    - No ordering -> maintain a hashmap or seen array
    - ordering -> sort then just do regular n-ary/bdt with an index

    No ordering:
    0. check if curGen is valid by check it's indicies to the used match
    1. if curSum == target - add to g_result and return
    2. if curSum > target just return
    3. recurse case
        4. select next number, decrement it in array/map
        5. recurse
        6. undo, increment in array/map
*/

using UMap = std::unordered_map< int, int >; // Map number to frequency - We can simplify this and use a vector, as we can just get the largest in the array and reserve that amount (it would be <= 100 )

    std::vector< std::vector< int >> g_result;

    void backtrack(
        std::vector< int >& uniques,
        int target,
        std::vector< int >& curGen,
        int curSum,
        int index,
        UMap frqnMap
    )
    {
        if ( curSum == target )
        {
            g_result.push_back( curGen );
            return;
        }

        if ( curSum > target )
            return;

        for( int i = index; i < uniques.size(); ++i )
        {
            // Have we used up all the occurences of the value?
            if ( frqnMap[ uniques[ i ] ] <= 0 ) continue;


            curGen.push_back( uniques[ i ] );
            frqnMap[ uniques[ i ] ]--;

            backtrack( uniques, target, curGen, (curSum + uniques[ i ]), i , frqnMap );

            curGen.pop_back();
            frqnMap[ uniques[ i ] ]++;

        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        unordered_map<int, int> freq;
        for (int x : candidates) ++freq[x];

        // extract unique values to iterate over
        vector<int> uniques;
        for (auto& [val, count] : freq) uniques.push_back(val);

        std::vector< int > curGen;
        backtrack( uniques, target, curGen, 0, 0, freq );

        return g_result;
    }

    // final note, it seems to me that sorting would be a better option and then we can just pass i + 1. as we only do it once, whereas checking the frequency map must happen every iteration
};
