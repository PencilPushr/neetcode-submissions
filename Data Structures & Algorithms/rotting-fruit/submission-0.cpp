class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        const int rows = grid.size();
        const int cols = grid[ 0 ].size();

        std::queue< pair< int , int >> q;
        int fresh = 0;

        // 1. Collect all rotten fruit and fresh fruit (to know if all fruit was reachable)
        for( int r = 0; r < rows; ++r )
        {
            for( int c = 0; c < cols; ++c )
            {
                if ( grid[ r ][ c ] == 2 )
                    q.push( { r, c } );

                if ( grid[ r ][ c ] == 1 )
                    ++fresh;
            }
        }

        printf("%d", fresh);

        const int directions[ 4 ][ 2 ] =
        {
            { 1, 0 },
            { 0 ,1 },
            {-1, 0 },
            { 0,-1 }
        };

        int minutes = 0;

        // 2. For all rotten fruit, look at adjacent fruit and rot them as well
        while( !q.empty() && fresh > 0)
        {
            // Create a snapshot of where we are, we only want to pop how many are in our current wave.
            const int waveSize = q.size();

            for( int i = 0; i < waveSize; ++i )
            {
                auto [ r, c ] = q.front();
                q.pop();

                for( auto& dir : directions )
                {
                    int nr = r + dir[ 0 ];
                    int nc = c + dir[ 1 ];

                    // Check for out of bounds
                    if ( nr < 0 || nr >= rows ||
                        nc < 0 || nc >= cols )
                        continue;

                    // Accept only fresh fruit to rot
                    if ( grid[ nr ][ nc ] != 1 )
                        continue;

                    // Rot current fruit, add it to the collection of rotten fruit
                    grid[ nr ][ nc ] = 2;
                    --fresh;
                    
                    q.push( { nr, nc } );
                }
            }

            ++minutes;
        }

        return fresh == 0 ? minutes : -1;
    }
};
