class Solution {
public:
/*
    Same idea as the last one.

    However, kahns is more natural.
    DFS might need a change, as we mark them, I guess when they've been processed we can push them onto an order vector?

    1. Build adj list ( and indegree if bfs )
    2. Fill queue with 0 indegrees
    3. Iterate over, every course that has 0 is added add to the vector<> answer
    4. Not sure, if there are many valid answers, return any of them - for now just assume:
        a. numCourses == answer.size()
*/
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector< vector< int >> adj( numCourses );
        vector< int > indegree( numCourses, 0 );

        // 1. Build adj list (and indegree)
        /*
            0
           / \
          /   \
         1     2
          \   /
           \ /
            3
        */
        for( const auto& p : prerequisites )
        {
            int course = p[ 0 ], prereq = p[ 1 ];
            adj[ prereq ].push_back( course );
            ++indegree[ course ];
        }

        // Now:
        /*
            0 -> [1, 2]
            1 -> [3]
            2 -> [3]
            3 -> []
        */

        // 2. Populate queue with all 0 indegree courses (courses with nothing pointing to them)
        /*
            Visually in indegree
                0 -> { 0 }  < this is the only one with nothing pointing
                1 -> { 1 }
                2 -> { 1 }
                3 -> { 2 }
        */
        std::queue< int > q;
        for( int course = 0; course < numCourses; ++course )
            if ( indegree[ course ] == 0 )
                q.push( course );

        // 3. Iterate over and fill out answer
        vector< int > result;
        while( !q.empty() )
        {
            int course = q.front(); q.pop(); // Got 0

            result.push_back( course );
            
            for( int nextCourse : adj[ course ] ) // Get 0 -> [ 1 , 2 ]
            {
                --indegree[ nextCourse ]; // 0 no longer points to 1 or 2, so one less degree
                
                if ( indegree[ nextCourse ] == 0 ) // indegree ( 1: 0, 2: 0 ), so add them
                    q.push( nextCourse );
            }
        }

        if ( numCourses != result.size() )
            return {};

        return result;
    }
};
