class Solution {

    /*
        Follow optimisation idea of using placeholder '#' to mutate the map as we iterate over it. (or use visited)

        Core idea:
        1. iterate over the map, until we encounter "land"
        2. dfs over land (NSEW) until finished:
            base case 1: clamp to bounds
            base case 2: water
            mutate map with 0/# placeholder
            update global result.

    */

    /*

    Failing this case:

    grid=[
        [0,0,1,0,0,0,0,1,0,0,0,0,0],
        [0,0,0,0,0,0,0,1,1,1,0,0,0],
        [0,1,1,0,1,0,0,0,0,0,0,0,0],
        [0,1,0,0,1,1,0,0,1,0,1,0,0],
        [0,1,0,0,1,1,0,0,1,1,1,0,0],
        [0,0,0,0,0,0,0,0,0,0,1,0,0],
        [0,0,0,0,0,0,0,1,1,1,0,0,0],
        [0,0,0,0,0,0,0,1,1,0,0,0,0]
    ]

    */

    int g_result = 0;
    int g_curIsland = 0;

    void dfs( vector<vector<int>>& grid, int x, int y)
    {
        // Base case 1: Clamp to map bounds on recursion
        if ( x < 0 || y < 0 || x == grid.size() || y == grid[ 0 ].size() )
            return;

        // Base case 2: Water
        if ( grid[ x ][ y ] == 0 )
            return;

        ++g_curIsland;

        // Mutate map so we don't revisit
        grid[ x ][ y ] = 0;

        dfs( grid, x + 1, y );
        dfs( grid, x - 1, y );
        dfs( grid, x, y + 1 );
        dfs( grid, x, y - 1 );

        g_result = std::max( g_result, g_curIsland );
    }


public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        // 1. Iterate over map until we encounter "land"
        for( int i = 0; i < grid.size(); ++i )
            for( int j = 0; j < grid[ 0 ].size(); ++j )
            {
                if ( grid[ i ][ j ] == 1 )
                {
                    g_curIsland = 0;
                    dfs( grid, i, j );
                }
            }

        return g_result;
    }
};
