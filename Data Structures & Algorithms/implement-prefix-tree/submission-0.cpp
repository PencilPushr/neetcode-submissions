class PrefixTree {

    struct TrieNode_t
    {
        TrieNode_t* m_children[ 26 ];
        bool m_isEndOfWord;

        TrieNode_t()
        {
            for( int i = 0; i < 26; ++i )
                m_children[ i ] = nullptr;

            m_isEndOfWord = false;
        }
    };

    using TrieNode = TrieNode_t;

    TrieNode* m_root;

public:
    PrefixTree() : m_root{ new TrieNode() }
    {}
    
    /*

        Create ptr to root, and "recursively" insert each character dfs at each level.
        Iterate downwards via a counter based on the size until we get to the end.
        Then set TrieNode.m_isEndOfWord = true;

    */
    void insert(string word) 
    {
        // Recursively insert the word. We want to go down the levels inserting each char dfs style.
        // That way if we have door and dog. we get:
        //      
        //                  ROOT
        //                d
        //               o
        //              g  o
        //            NULL  r
        //                   NULL

        TrieNode* cur = m_root;
        for( int i = 0; i < word.size(); ++i )
        {
            int index = word[ i ] - 'a'; // Convert char to 0-25 index

            if ( cur->m_children[ index ] == nullptr )
                cur->m_children[ index ] = new TrieNode();

            cur = cur->m_children[ index ];
        }

        cur->m_isEndOfWord = true;
    }
    
    /*
        Go through each node, checking that it exists until we hit m_isEndOfWord = true
    */
    bool search(string word) 
    {
        TrieNode* cur = m_root;

        for( int i = 0; i < word.size(); ++i )
        {
            int index = word[ i ] - 'a';

            if ( cur->m_children[ index ] == nullptr && cur->m_isEndOfWord == false )
                return false;

            cur = cur->m_children[ index ];
        }

        if ( cur->m_isEndOfWord == true )
            return true;

        return false;

    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* cur = m_root;

        for( int i = 0; i < prefix.size(); ++i )
        {
            int index = prefix[ i ] - 'a';

            if ( cur->m_children[ index ] == nullptr )
                return false;

            cur = cur->m_children[ index ];
        }

        return true;
    }
};
