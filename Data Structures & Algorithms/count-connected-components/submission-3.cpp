class Solution {
public:
/*
    So far, I know how to traverse, detect loops and skip parents

    I'm assuming for this, when we create a boolean array, we create a counter and just count.

    It's not a great solution however, it's rather brute force.

    In essence:
     1. build adj
     2. iterate
     3. check visited/seen array.
        4. restart iteration, until bool area is completely true, incrementing counter each time.

    Actually that's not so bad - o(n) worst case, as nodes will be marked true after search, so we skip them.

    Alternative solution is 

    cases/invariants:
    1. Complete
    2. broken into n connectd nodes
    3. every node is independent. 

    0. There is no graph...? if n == 0 => return 0. Weird case to handle; skipping for now.
*/
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        // 1. Build adj list - this is bidirectional we need to track parents later
        /*
            0 -- 1   3
                 |   |
                 2   4
        */
        vector< vector< int >> adj( n );
        for( auto node : edges )
        {
            int u = node[ 0 ]; // current
            int v = node[ 1 ]; // neighbour

            adj[ u ].push_back( v );
            adj[ v ].push_back( u );
        }

        /* Now we have

            0 -> [ 1 ]
            1 -> [ 0, 2 ]
            2 -> [ 1 ]

            3 -> [ 4 ]
            4 -> [ 3 ]
        */

        // 2. Seen/visited array + iterate
        vector< int > seen( n, 0 );
        
        //dfs( 0, -1, adj, seen ); // We don't care about the result of dfs - whether there was a cycle or not,
        // We just want to see if we filled seen with true.

        int counter = 0; // Assume there is one whole graph at first (case 1). Edit: don't need the above dfs
        // If we hadnle it in the loop we hadnle n == 0 case anyway.
        for( int i = 0; i < seen.size(); ++i )
        {
            if ( ! seen[ i ] )
            {
                ++counter;
                dfs( i, /*-1,*/ adj, seen );
            }
        }

        return counter;
    }

    void dfs( 
        int u,
        // int parent,
        vector< vector< int >>& adj,
        vector< int >& seen
    )
    {
        seen[ u ] = 1;

        for( int v : adj[ u ] )
        {
            // Edit, we don't care if there is a cycle, so we don't need parent.
            //   just use seen to check it's not grey.

            // if ( v == parent ) continue;            
            //if ( seen[ v ] == 1 ) return false; // Prevent looping infinitely
            
            if ( seen[ v ] == 1) continue;
            dfs( v,/* u,*/ adj, seen );
        }
    }
};
