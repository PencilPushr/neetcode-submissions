class Solution {
public:
/*
    Completely lost. Had to cheat.

    This is cycle detection - we are checking if we have a DAG.

    There are two solutions - DFS and BFS (topological sort)

    Both require building an adjacency list first.
    Mentally you can think of it like:
        You populate buckets (a.first) with their connections (a.second[i]) 

    Example:
        [1, 0]

    means:
        0 -> 1

    because course 0 must happen before course 1.
    
DFS

        Use 3 states:

        0 = unvisited
        1 = currently visiting
        2 = completely processed

    1. Build adj list
    2. Create a visited array for each iteration
    3. recurse and go through, if it's within the visited array - found loop

    Alternatively we can use:
    Hashmap and a currently visiting set. Map current course to it's prequisites, dfs, if loop - terminate.

BFS 

    1. Build adj list
    2. ...
    Use Kahn's topological sort.

    Need:
        adjacency list
        indegree array

    Repeatedly process courses whose indegree == 0.

    If we can process all numCourses:
        no cycle

    If some courses remain:
        they are trapped in a cycle.
*/

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // 1. Build adj list:
        /*
            0
           / \
          /   \
         1     2
          \   /
           \ /
            3
        */
        vector< vector< int >> adj( numCourses );
        for( const auto& p : prerequisites )
        {
            int course = p[0];
            int prerequisite = p[1];

            adj[ prerequisite ].push_back( course );
        }

        // Now:
        /*
            0 -> [1, 2]
            1 -> [3]
            2 -> [3]
            3 -> []
        */

        // 2. DFS with colours/numbers:
        // 0 = unvisited
        // 1 = visiting
        // 2 = done
        vector<int> state(numCourses, 0);
        for( int course = 0; course < numCourses; course++ ) // Only works if it is 0..m contiguously
        {
            if ( !dfs( course, adj, state ) )
                return false;
        }

        return true;
    }

    bool dfs( 
        int course,
        vector< vector< int >>& adj, 
        vector< int >& state
    )
    {
        // We encountered a node that we were just visiting 
        if ( state[ course ] == 1 )
            return false; // Found cycle

        if ( state[ course ] == 2 )
            return true; // Already processed

        state[ course ] = 1;

        for( int next : adj[ course ] )
        {
            if ( !dfs( next, adj, state ) )
                return false;
        }

        state[ course ] = 2; // Finished processing
        return true;
    }
};
