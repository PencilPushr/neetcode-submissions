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
    // 3. If we encounter already seen v, and parent, then return the two vertices/edge.

    Hint: The above might work - however, suggested that you can search before you insert
            if there is already a connection between the two nodes.
            Can you reach v from u already?
            As we insert new nodes in the build adj loop, check if it's already reachable.

     Why it was wrong:
    - The first back-edge DFS finds is *a* cycle edge, but not necessarily
      the one the problem wants: the cycle edge that appears LAST in `edges`.
      DFS order comes from adj list layout, not input order.

    BETTER IDEA
    -----------
    Use DFS only to find WHICH vertices are on the cycle.
    Use `edges` (the only place input order lives) to pick the answer.

    1. Build the adjacency list (undirected, so push both ways).
    2. DFS from vertex 1, recording parents[] and seen[].
    3. Skip v == parents[u]: that's the edge we arrived on, not a cycle.
    4. If v is already seen (and isn't our parent), (u, v) closes the cycle.
       Walk parents[] from u back up to v, marking every vertex on the way,
       then mark v. That set is exactly the cycle.
    5. Return true up the call stack to stop the search; `cycle` is filled
       in by reference, so nothing else needs passing back.
    6. Scan `edges` from the back. The first edge with both endpoints on
       the cycle is the answer.
       - Membership is enough: a tree + one edge has exactly one cycle and
         no shortcut edges across it, so both-endpoints-marked => cycle edge.

    ALTERNATIVE (union-find)
    ------------------------
    Search before you insert: add edges in input order, and before adding
    (u, v) ask "can I already reach v from u?". The first yes is the answer,
    and it's automatically the last cycle edge in input order.

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
        vector< vector< int >> adj( n + 1);
        for( auto e : edges )
        {
            int u = e[ 0 ];
            int v = e[ 1 ];

            // Otherwise push back and we try again
            adj[ u ].push_back( v );
            adj[ v ].push_back( u );
        }

        vector< int > parents( n + 1, -1 );
        vector< int > seen   ( n + 1, 0  );
        std::unordered_set< int > cycle;

        dfs( 1, parents, adj, seen, cycle );

        for( int i = n - 1; i >= 0; --i )
        {
            const auto& e = edges[i];
            if (cycle.count(e[0]) && cycle.count(e[1]))
                return e;
        }

        return {};
    }

    bool dfs( 
        int u,
        vector< int >& parents,
        vector< vector< int >>& adj,
        vector< int >& seen,
        std::unordered_set< int >& cycle
    )
    {
        seen[ u ] = true;

        for( int v : adj[ u ] )
        {
            // Don't back up on ourselves
            if ( v == parents[ u ] ) continue;

            if ( seen[ v ] )
            {
                int curr = u;
                while( curr != v )
                {
                    cycle.insert( curr );
                    curr = parents[ curr ];
                }
                
                cycle.insert( v );
                return true;
            }

            parents[ v ] = u;
            if ( dfs( v, parents, adj, seen, cycle ) )
                return true;
        }


        return false;
    }
};    