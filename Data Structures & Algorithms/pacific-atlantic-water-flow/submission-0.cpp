class Solution {
public:

    int rows = 0;
    int cols = 0;

    void dfs( const vector< vector< int >>& grid, int r, int c, int parentHeight, vector< vector< char >>& visited )
    {
        // Out of bounds
        if ( r < 0 || r >= rows || c < 0 || c >= cols ) return;

        // Have we visited?
        if ( visited[ r ][ c ] ) return;

        // Is this a smaller height?
        if ( grid[ r ][ c ] < parentHeight ) return ;

        visited[ r ][ c ] = true;

        // Traverse directions
        dfs( grid, r + 1, c, grid[ r ][c ], visited );
        dfs( grid, r - 1, c, grid[ r ][c ], visited );
        dfs( grid, r, c + 1, grid[ r ][c ], visited );
        dfs( grid, r, c - 1, grid[ r ][c ], visited );
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        rows = heights.size();
        cols = heights[ 0 ].size();

        vector< vector< char >> pacific( rows, vector< char >( cols, false ));
        vector< vector< char >> atlantic( rows, vector< char >( cols, false ));

        // Try the top and bottom cells
        for (int r = 0; r < rows; ++r) 
        {
            dfs( heights, r, 0,        heights[ r ][ 0 ],        pacific );
            dfs( heights, r, cols - 1, heights[ r ] [cols - 1 ], atlantic );
        }

        // Try left and right cells
        for (int c = 0; c < cols; ++c) 
        {
            dfs( heights, 0, c,        heights[ 0 ][ c ],        pacific );
            dfs( heights, rows - 1, c, heights[ rows - 1 ][ c ], atlantic );
        }

        vector< vector< int >> result;

        // Find overlap between pacific and atlantic cells
        for( int r = 0; r < rows; ++r )
            for( int c = 0; c < cols; ++c )
                if ( pacific[ r ][ c ] && atlantic[ r ][ c ] )
                    result.push_back( { r, c } );

        return result;
    }
};
