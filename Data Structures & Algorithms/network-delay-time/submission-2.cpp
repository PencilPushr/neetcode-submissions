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
        using Pair = std::pair< int, int >;
        // We have times = [[1,2,1],[2,3,1],[1,4,4],[3,4,1]], n = 4, k = 1

        vector< vector< Pair >> adj( n + 1 );
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
        std::vector< int > distance( n + 1, INT_MAX ); // 1e9, 1e9, 1e9, 1e9,
        distance[k] = 0;                                // 1e9, 0, 1e9, 1e9
        
        std::vector< int > visited( n + 1 );            // 0, 0, 0, 0
        priority_queue< Pair, vector< Pair >, greater<> > pq;   // { node , time }
        pq.push( { 0, k } );

        while( !pq.empty() )
        {
            auto u = pq.top(); pq.pop();

            if ( visited[ u.second ] )
                continue;

            visited[ u.second ] = true; // i1 v= 0, 1, 0, 0

            for( const auto& v : adj[ u.second ] )// i1 = {2:1, 4:4}
            {
                if ( visited[ v.first ] == true ) 
                    continue; 

                if ( u.first + v.second >= distance[ v.first ] )// dist[2] = 1e9, dist[4] = 1e9
                    continue;
                
                distance[ v.first ] = u.first + v.second;// dist[2] = 1, dist[4]=4
                pq.push({ u.first + v.second, v.first}); // 2, 4
            }
        }

        // Debug
        for( const auto& i : distance )
            cout << i << " ";

        int result = *std::max_element( distance.begin() + 1, distance.end() );

        return result == INT_MAX ? -1 : result;
    }
};