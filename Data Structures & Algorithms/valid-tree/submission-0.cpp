class Solution {
public:
/*
    Let's start with the definition of a tree.
    1. No loops
    2. Every node is connected
    3. There can only be 1 root node? (one node with 0 indegree's)

    This also handles our invariants/cases.

    So we can use dfs state (colouring) or kahns for cycle detection.
    Additionally, any node must be reachable, you cannot have two floating trees

*/
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        /*
                0
              / | \
             /  |  \
            1   2   3
            |
            |
            4
        */

        // Build adj list 
        vector< vector< int >> adj( n );
        for( const auto e : edges )
        {
            int u = e[ 0 ]; // Current
            int v = e[ 1 ]; // Neighbour

            adj[ u ].push_back( v );
            adj[ v ].push_back( u );;
        }

        // Now:
        /*
            0 -> [1, 2, 3]
            1 -> [4]
            2 -> []
            3 -> []

            Note this doesn't actually work, we must have two pushbacks,
            remember to do invariants/cases - simplest case 0 -- 1, this will produce a cycle,
            So you need to carry down more information, parent.

            0 -> [1, 2, 3]
            1 -> [0, 4]
            2 -> [0]
            3 -> [0]
            4 -> [1]
        */
        
        // Here we would need to check that there is one root node possible, in topological sort
        // this would be a little easier, as it would be first in the topological array - dfs can have top sort?
        //      I think on the CPH pdf from usaco, you have visited array, and two other structures
        //      Alternatively, I'm thinking perhaps a map/set is possible - if one node is separate from the rest of
        //      the graph, it would have nothing pointed to it, you can keep a count of the number of nodes as you go through that do not have something pointing to it, then have a counter; if its 1 then that's fine. This also lets you know which node(s) is the offender(s)

        // Begin dfs - we want to iterate over every node ( lhs in the above diagram ( lhs:0 -> rhs: [1, ...]) )
        //             Checking for: loops.
        vector< bool > seen( n, false );
        
        // No need to loop over every node in dfs:
        /*
        0 -- 1
        2 -- 3
            Two graphs, we want to see if we follow from 0, can we get to every other node?
            + because this is UNDIRECTED, we should be able to pick any node and traverse the entirety
        */
        if ( ! dfs( 0, -1, adj, seen) )
            return false;

        // Check that we were able to visit all nodes - connectivity.
        for( bool nodeVisited : seen )
            if ( !nodeVisited )
                return false;

        return true;
    }

    bool dfs( int curNode, int parent, vector< vector< int >>& adj, vector< bool >& seen )
    {
        seen[ curNode ] = true;

        // Remember:  { 0 -> [1, 2, 3], 1 -> [4], ... we want to iterate the rhs, so our curNodes neighbours
        // But:
        //      1. Don't go to a parent
        //      2. 
        for( int next : adj[ curNode ] )
        {
            if ( next == parent ) continue;         // the edge we came in on - not a cycle
            if ( seen[ next ] ) return false;      // any other visited node closes a real cycle
            if ( ! dfs( next, curNode, adj, seen ) )
                return false;
        }

        return true;
    }
};
