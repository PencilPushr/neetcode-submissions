class Solution {
public:
/*
    3 Solutions:
     - dfs
     - SPFA (bfs)
     - Djikstra

     1. dfs
        a. Create adj list, 
        b. time/distance array (index is element's distance from k to where it is) (1:0 - start node, no dist) 2:1
        c. single dfs, take in adj and distance, we are filling distance.
        d. find max_element in distance array.

     2. SPFA
        a. Create adj list
        b. time/distance array
        c. branch out, update the distance, if there is a smaller to x node, update it
        d. find max_element in distance array
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
        std::vector< int > distance( n + 1, INT_MAX );
        distance[k] = 0;
        
        queue< pair< int, int >> q;
        q.push( { k, 0 } );

        while( !q.empty() )
        {
            auto u = q.front(); q.pop();

            for( const auto& v : adj[ u.first ] )
            {
                if ( u.second + v.second >= distance[ v.first ] )
                    continue;

                distance[ v.first ] = u.second + v.second;
                q.push({ v.first, u.second + v.second });
            }
        }

        // Debug
        for( const auto& i : distance )
            cout << i << " ";

        int result = *std::max_element( distance.begin() + 1, distance.end() );

        return result == INT_MAX ? -1 : result;
    }
};