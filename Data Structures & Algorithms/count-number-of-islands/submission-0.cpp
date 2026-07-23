class Solution {
public:

    /*
        Graph, maybe backtracking problem?

        Use backtracking to determine connected pieces of islands.
        Use dfs once we encounter land.
        keep a track via visited array of all the cells, so we can skip nodes we've seen.

        Let's keep the backtrack shape having solved word search and attempted (but failed) word search II.

        1. Iterate regularly until we find "land":
        2. Enter recursion:
            a. check nsew for next piece of land (diagonal doesn't count)
            b. update seen/visited array. 
        3. If we exit a dfs, it means we have found a complete island => result++;


    */

    int g_result = 0;
    vector< vector< bool >> g_visited{};

    void backtrack( vector< vector< char >>& grid, int x, int y ) 
    {
        // 1. Base case: Out of bounds check (use >=)
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
            return;

        // 2. Base case: Water OR already visited
        if (grid[x][y] == '0' || g_visited[x][y])
            return;

        // 3. Mark visited
        g_visited[x][y] = true;

        // 4. Recurse NSEW
        backtrack(grid, x - 1, y);
        backtrack(grid, x + 1, y);
        backtrack(grid, x, y + 1);
        backtrack(grid, x, y - 1);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty() || grid[0].empty()) return 0;

        g_visited.assign(grid.size(), vector<bool>(grid[0].size(), false));

        for( int x = 0; x < grid.size(); ++x )
            for( int y = 0; y < grid[ 0 ].size(); ++y )
            {
                if ( grid[ x ][ y ] == '1' && g_visited[ x ][ y ] == false ) // It's land and we've not visited it before
                {
                    backtrack( grid, x, y );
                    ++g_result;
                }
            }

        return g_result;
    }
};
