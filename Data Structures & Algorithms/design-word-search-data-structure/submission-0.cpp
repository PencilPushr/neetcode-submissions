class WordDictionary 
{
    struct TrieNode_t
    {
        TrieNode_t* m_children[ 26 ]{ nullptr };
        bool m_isEndOfWord = false;
    };

using TrieNode = TrieNode_t;

    TrieNode_t* m_root;

    // Base cases, we are null or end of word ( perform final check )
    bool dfs( std::string& word, int pos, TrieNode* root )
    {
        if ( !root )
            return false;

        if ( pos == word.size() )
            return root->m_isEndOfWord;

        if ( word[ pos ] == '.' )
        {
            for( int i = 0; i < 26; ++i )
            {
                if ( dfs( word, pos + 1, root->m_children[ i ] ) )
                    return true;
            }
            return false;
        }
        else
        {
            int offset = word[ pos ] - 'a';
            return dfs( word, pos + 1, root->m_children[ offset ] );
        }
    }

public:
    WordDictionary() 
    {
        m_root = new TrieNode();
    }
    
    void addWord(string word) 
    {
        auto* cur = m_root;
        
        for( int i = 0; i < word.size(); ++i )
        {
            int offset = word[ i ] - 'a';

            if ( cur->m_children[ offset ] == nullptr )
                cur->m_children[ offset ] = new TrieNode();

            cur = cur->m_children[ offset ];
        }

        cur->m_isEndOfWord = true;
    }

    bool search(string word) 
    {
        return dfs( word, 0, m_root );
    }
};
