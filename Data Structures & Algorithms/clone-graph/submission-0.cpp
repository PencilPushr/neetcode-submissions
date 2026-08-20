/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*

    This memory leaks but whatever.

    This seems to be approaching the idea of using/converting via an adjacency list.
    However we aren't building it ourselves like other problems. Instead we already given one.

    The idea for this is to dfs.
    For example 1
        [[2],[1,3],[2]]
        1   ->  2
                |
                v
                3
        
        So first we keep a track of which node's we've already visited.
        Then create our own copy, new it, and then iterate over it's neighbours, if we have visited it before, go back up cstack
        Otherwise, get current nodes' value, go through it's neighbours, get it's return value and make it ours.
*/

class Solution {
public:

    Node* dfs( Node* root, std::unordered_map< Node*, Node* >& clones)
    {
        // We got passed nothing - edge case :: Input = nullptr 
        if ( !root )
            return nullptr;

        // We have already constructed this node.
        // Return the CLONED node, not the original.
        if ( clones.count( root ) )
            return clones[root];

        // Clone current node.
        Node* copy = new Node( root->val );

        // Record the mapping BEFORE traversing neighbours.
        //
        // This is what breaks cycles.
        clones[ root ] = copy;

        // Connect this node to all of the neighbours
        for( const auto& n : root->neighbors )
        {
            copy->neighbors.push_back( dfs( n, clones ) );
        }

        return copy;
    }


    Node* cloneGraph(Node* node) 
    {
        std::unordered_map< Node*, Node* > clones;
        return dfs( node, clones );
    }
};
