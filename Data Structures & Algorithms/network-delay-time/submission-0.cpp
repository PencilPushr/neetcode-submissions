class Solution {
public:
/*
    This immediately tells me from the input
    build adj list
    use djikstra

    we have a connection + time/weight - time it takes signal to travel as an int.
    AND it's directed.

    We are looking for the shortest path for ALL nodes to receive the signal (if possible).
    This seems to me to say BFS, rather than dfs which asks (is there a path/connection)

    Maybe we can use a priority_queue and queue it up with djikstras..

    Ok let's try the transformation learning. 
    Brute force ... ? Not even sure how you would brute force this.

    Input: times = [[1,2,1],[2,3,1],[1,4,4],[3,4,1]], n = 4, k = 1

    Output: 3

    My model is:
        1
       / \
      2   4
       \ /
        3

    we start off at 1, which in the adj:  1 -> [ 2, 4 ]
    Now, 2 is cheap at 1, 4 is expensive at 4.
    queue = 2, 4

    now process 2, adj: 2 -> [ 3 ]
    no other connections, but its also cheaper than 4 at 4 
    Note: We might actually be able to do dfs, and it might be more intuitive, as we can iterate first
    down the cheaper options, to get to the nodes.

    This honestly rings a bell with a minimum spanning tree.

    Regardless, I will implement first with BFS, then attempt with DFS.
    
*/
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // We have times = [[1,2,1],[2,3,1],[1,4,4],[3,4,1]], n = 4, k = 1

        vector< vector< pair< int, int >>> adj( n + 1 );
        for( const auto& time : times )
        {
            const int u = time[ 0 ];
            const int v = time[ 1 ];
            const int t = time[ 2 ];

            adj[ u ].push_back( { v, t } );
        }

        // Now have:
        /*
            1 -> [ { 2, 1 }, { 4, 4 } ]
            2 -> [ { 3, 1 } ]
            3 -> [ { 4, 1 } ]
        */
        // Maybe we can have a path compression structure? similar to dsu?
        // Then we could query 1->3 = 2. I guess it would pretty much be a trie mixed with dsu?
        // Or maybe opt for a size array approach?
        std::vector< int > distance( n + 1, INT_MAX );
        dfs( k, 0, adj, distance );

        int result = *std::max_element( distance.begin() + 1, distance.end() );

        return result == INT_MAX ? -1 : result;
    }

    void dfs( int u, int time, vector< vector< pair< int, int >>>& adj, vector< int >& distance )
    {
        // If the current time to get to this node is greater than already stored - we found a slower path.
        if ( time >= distance[ u ] ) return;
        // Set current time it takes to get to this node.
        distance[ u ] = time;

        for( const auto& v : adj[ u ] )
            dfs( v.first, time + v.second, adj, distance );
    }
};