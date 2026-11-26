class Solution {
public:
/*
    Objective:
    Reconstruct the graph

    We are constructing a path in this case, so we can't use DSU.
    Leaving:
    SPFA, DFS, BFS, Dijkstra, topological sort(graph colouring, kahns)

    Current appraoch:
        1. build adj list.
        2. 

    3 steps of ...
    Model
    Transform
    ...?

    What we know.
    JFK is entry node.
    When performing dfs, create lambda that compares lexographically the text to place the next node to visit.
    There is at least one valid flight path
    It is potentially undirected. (in which case you have two tickets to travel from).

    Cases:
    Input: tickets = [["BUF","HOU"],["HOU","SEA"],["JFK","BUF"]]
    Output: ["JFK","BUF","HOU","SEA"]

    // undir:
    Input: tickets = [["HOU","JFK"],["SEA","JFK"],["JFK","SEA"],["JFK","HOU"]]
    Output: ["JFK","HOU","JFK","SEA","JFK"]
*/
    // auto lexCompare = []( const string& a, const string& b ) -> int
    // {
    //     std::size_t n = std::min( a.size(), b.size() );
    //     for( std::size_t i = 0; i < n; ++i )
    //         if ( a[ i ] != b[ i ])
    //             return a[ i ] < b[ i ];
    //     return a.size() < b.size();
    // };

    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        // 1. Build adj
        // [["BUF","HOU"],["HOU","SEA"],["JFK","BUF"]]
        unordered_map<string, vector<string>> adj;
        for( const auto& t : tickets )
        {
           const string& u = t[0];
           const string& v = t[1];

           adj[ u ].push_back( v );
        }

        // 2. Sort for the smallest
        for( auto& [ u, dest ] : adj )
            std::sort( dest.begin(), dest.end(), std::greater<>() );

        vector< string > path;

        dfs( "JFK", adj, path );

        std::reverse( path.begin(), path.end() );

        return path;    
    }

    void dfs(
        const string& u, 
        unordered_map< string, vector< string >>& adj, 
        vector< string >& path 
    )
    {
        while( !adj[ u ].empty() )
        {
            // Same like bfs, top and pop.
            string v = adj[ u ].back();
            adj[ u ].pop_back();

            dfs( v, adj, path );
        }
        
        // Add the end
        path.push_back( u );
    }
};
