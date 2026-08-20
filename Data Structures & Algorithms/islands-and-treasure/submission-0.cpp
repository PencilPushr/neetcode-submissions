class Solution {
public:
/*
    1. Find all 0's
        Recording all positions.
    2. DFS outwards from said position, with a counter passed down

    Only issue for an edge case is, what if 2 treasures exist on an island?

        [3,-1,0,1],
        [2,2,1,-1],
        [1,-1,2,-1],
        [0,-1,3,4]

    Two ways:
    1. DFS with correction if cell is same or better than - stop
    2. BFS, similar idea above, but can be applied to multi-source

*/
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        if ( grid.empty() || grid[ 0 ].empty() )
            return;

        const int rows = grid.size();
        const int cols = grid[ 0 ].size();

        queue<pair<int, int>> q;

        // 1. Start BFS from every treasure simultaneously.
        for ( int r = 0; r < rows; ++r )
        {
            for ( int c = 0; c < cols; ++c )
            {
                if (grid[  r] [c ] == 0)
                    q.push( { r, c } );
            }
        }

        const int directions[ 4 ][ 2 ] =
        {
            { 1,  0 },
            {-1,  0 },
            { 0,  1 },
            { 0, -1 }
        };

        // 2. Expand outward from all treasures.
        while ( !q.empty() )
        {
            auto [ r, c ] = q.front();
            q.pop();

            for ( auto& dir : directions )
            {
                int nr = r + dir[ 0 ];
                int nc = c + dir[ 1 ];

                // Out of bounds.
                if ( nr < 0 || nr >= rows ||
                     nc < 0 || nc >= cols )
                {
                    continue;
                }

                // Ignore walls and already-visited cells.
                if ( grid[ nr ][ nc ] != INT_MAX)
                    continue;

                grid[ nr][ nc ] = grid[ r ][ c ] + 1;

                q.push( { nr, nc } );
            }
        }

        return;
    }
};
