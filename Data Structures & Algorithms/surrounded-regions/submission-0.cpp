class Solution {
public:
    /**

    1. Find the inversion of properties/invariants. To avoid an O(n^2) or worse solution.
        a. find all 'O'

        1. For all O's, check they are connected horizontally/verically
        2. Form this into a struct/map of Region
        3. Check for all O's in Region that it is not enclosed by X's/none are on the edge

        Alternatively, just 
        1. check on the edge of the board - collect all O's
        2. Form any regions that are touching the side/edge of the board, these are the only ones we care about
        3. Wipe everything except for the developed regions

    */

    void dfs( 
        const vector< vector< char >>& board, 
        int r, 
        int c, 
        vector< vector< char >>& visited 
    )
    {
        // Clamp
        if ( r < 0 || r >= board.size()     || 
             c < 0 || c >= board[ 0 ].size() ) 
            return;

        // Check if we have already visited - or it's ocean
        if ( visited[ r ][ c ] || board[ r ][ c ] != 'O')
            return;

        // Build region - add to visited and region
        visited[ r ][ c ] = true;

        // Check up, right, down, left
        dfs( board, r + 1, c    , visited);
        dfs( board, r    , c + 1, visited);
        dfs( board, r - 1, c    , visited);
        dfs( board, r    , c - 1, visited);
    }

    void solve( vector<vector<char>>& board ) 
    {
        const int rows = board.size();
        const int cols = board[ 0 ].size();

        std::vector< std::pair< int, int >> candidates;

        // 1. Collect all O's around the side/edge

        // Top + bottom
        for( int c = 1; c < cols - 1; ++c )
        {
            if ( board[ 0 ][ c ] == 'O' )        candidates.push_back({ 0, c });
            if ( board[ rows - 1 ][ c ] == 'O' ) candidates.push_back({ rows - 1, c });
        }
        // Left + right
        for( int r = 0; r < rows; ++r )
        {
            if ( board[ r ][ 0 ] == 'O' )        candidates.push_back({ r, 0 });
            if ( board[ r ][ cols - 1 ] == 'O' ) candidates.push_back({ r, cols - 1 });
        }

        // 2. Build regions

        // Can use bfs/dfs - just picking dfs for fun
        vector< vector< char >> visited( rows, vector< char >( cols, 0 ) );
        for( const auto& i : candidates )
            dfs( board, i.first, i.second, visited);

        // 3. Clear entire board - except for cells marked
        for( int r = 0; r < rows; ++r )
            for( int c = 0; c < cols; ++c )
            {
                if ( !visited[ r ][ c ] )
                    board[ r ][ c ] = 'X';
            }
    }
};
