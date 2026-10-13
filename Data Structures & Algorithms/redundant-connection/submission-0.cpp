class Solution {
public:
/*

    Seems to be a similar approach to finding a cycle.
    For now assume we can be greedy and remove the first connection.

    Invariants:
    1. Complete graph; not split
    2. originally no cycles, 1 added later
    3. no self loop

    cases:
    1. Loop added to create circle
    2. Loop between two indiscriminant nodes

    // 1. build adj list
    // 2. iterate dfs with seen array
    // 3. First loop found -> mark fun stretch (pop-back the parent and cur node)?

    Hint: The above might work - however, suggested that you can search before you insert
            if there is already a connection between the two nodes.
            Can you reach v from u already?

*/
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        // 1.
        /*
            1 -- 2
            |    |
            3 -- 4
        */
        vector< vector< int >> adj( n + 1 );
        for( auto e : edges )
        {
            vector< int > seen( n + 1, 0 );

            int u = e[ 0 ];
            int v = e[ 1 ];

            // Is it already possible to travel from here (u) to there (v)
            if ( dfs( v, u, adj, seen ) )
                return { u, v };

            // Otherwise push back and we try again
            adj[ u ].push_back( v );
            adj[ v ].push_back( u );
        }

        return {};
    }

    bool dfs( 
        int u,
        int end,
        vector< vector< int >>& adj,
        vector< int >& seen
    )
    {
        seen[ u ] = 1; // grey

        // Go through all the edges u is connected to
        for( int v : adj[ u ] )
        {
            if ( seen[ v ] ) continue; // We've already encountered this edge

            if ( v == end ) return true; // Hey, we can visit this edge already!

            if ( dfs( v, end, adj, seen ) ) // See if anyone down the chain succeeds
                return true;
        }

        seen[ u ] = 2; // black

        return false;
    }
};    
