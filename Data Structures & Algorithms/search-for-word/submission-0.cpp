class Solution {
public:
    
/*
    Current idea is to iterate every time, or find all word[0] positions, and for all positions then check neighbours


    1. Find all candidates with B
    2. Backtrack on candidates with B
    3. backtrack on all neighbours until failure or success
    
    if none of the neighbours allows you to build the word then fail


    Some optimisations I'm thinking, you can pass in row and col as the current index and keep iterating it until you find 
    another candidate that matches word[ 0 ], then perform the rest of the backtracking.
    This way all the iteration and backtracking exists only in the backtrack function

    1. Find collect all x,y coords of candidates ( first letter matches )
    2. Iterate over candidates:
        3. Check neighbours
        4. If neighbour found => return true!
    5. if finished with candidates => return false;
    6. OR results together and return upwards
*/

    bool backtrack(
        vector< vector< char >>& board,
        pair< int, int > curpos,
        set< pair< int, int >>& visited,
        string& word,
        int index
    )
    {
        // Base case - we reached the end of the word
        if ( index == word.length() )
            return true;

        // Bounds check - prevent recursion beyond board
        if ( curpos.first < 0 || curpos.second < 0 ) return false;
        if ( curpos.first >= board.size() || curpos.second >= board[ 0 ].size() ) return false;

        // check we aren't visiting somewhere we already have been - We aren't looping on ourselves
        if ( visited.find( curpos ) != visited.end() )
            return false;

        // Cur position matches a word - guard clause
        if ( board[ curpos.first ][ curpos.second ] != word[ index ] ) 
            return false;

        // This is part of the word! :)
        visited.insert( { curpos.first, curpos.second } );

        bool result = backtrack(board, { curpos.first + 1, curpos.second }, visited, word, index + 1) || // Up
                      backtrack(board, { curpos.first, curpos.second + 1 }, visited, word, index + 1) || // Right
                      backtrack(board, { curpos.first - 1, curpos.second }, visited, word, index + 1) || // Down
                      backtrack(board, { curpos.first, curpos.second - 1 }, visited, word, index + 1);   // Left

        // This is kind of messy: future reference, check UDLR. Skip the pair, just use { x, y } it's easier.
        // Probably use more globals to keep a track of state instead of passing it by function, it's irritating to track.

        visited.erase( curpos );


        return result;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        // Skip the candidates for now. 
        // Just iterate directly

        set< pair< int, int >> visited;

        for( int i = 0; i < board.size(); ++i )
            for( int j = 0; j < board[ 0 ].size(); ++j )
                if (board[ i ][ j ] == word[0])
                    if ( backtrack( board, { i, j }, visited, word, 0 ) )
                        return true;
                
        return false;
        
    }
};
