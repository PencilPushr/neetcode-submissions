class Solution {
public:
/*
    Similar to Valid tree, and course schedule I and II. We want to find if the graph is connected.

    However - we want to know how many components are connected.
    This Number of connected components in an undirected graph means we aren't looking at cycle detection.

    In the case of :
    Input:
    n = 5, edges = [[0,1],[1,2],[3,4]]
    Produces:
    0 -- 1     3 -- 4
         |
         |
         2

    Output: 2

    Invariants/cases:
    1. Graph is fully connected
    2. Graph has n connections
        a. The graph is partially split
        b. Every single edge(node) is it's own component

    So the current strategy is:
    1. Create adj list
    2. Iterate through (kahns or dfs) - create seen array.


    Union find approach.
    1. Assign parents to all nodes to themselves.
    2. Loop through all edges
        3. attempt to combine, if unite fails, means there was no connection
        so increment counter
    4. return counter
*/

    std::vector< int > parents;
    std::vector< int > size;

    int find( int u )
    {
        if ( u == parents[ u ] )
            return u;
        
        return parents[ u ] = find( parents[ u ] );
    }

    bool unite( int u, int v )
    {
        int rootU = find( u );
        int rootV = find( v );

        if ( rootU == rootV )
            return false;

        // Guard clause - force rootU to always be bigger by swapping values
        if ( rootU < rootV )
            std::swap( rootU, rootV );

        // rootV is now a child of rootU
        parents[ rootV ] = rootU;

        // update size
        size[ rootU ] += size[ rootV ];

        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) 
    {
        parents.assign( n, 0 );
        size.assign( n, 1 );

        std::iota( parents.begin(), parents.end(), 0 );

        int components = n; // initially every element is alone (every vertice is unconnected)
        for( const auto& e : edges )
            if ( unite( e[ 0 ], e[ 1 ] ) )
                --components;

        return components;
    }
};
