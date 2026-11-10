class Solution {
/*

    I have two ideas on approach on converting the words or how to iterate over them.
    Previously have used adj list, dsu doesn't require it.
    1. Convert each word, into a number - similar to a hash.
        This would be similar to group anagrams, would maintain different groupings, and somehow figure out relations
    2. as we enumerate the neighbours, will have to check which words are viable (have 1 letter difference).

    I don't like the second option due to speed, but I don't have a choice at the moment. As the first option
    isn't very clear to me how it would work correctly. 

    It clearly makes a graph as words have a 1 letter association between them.

    Working from brute force, we would have an n^2 * 2m solution, every word must be scanned, 
    and each word must have it's letters scanned.

    Let's start from brute force and then work on the invariants and see how I could progress upwards.
    But this won't give you the optimal minimum transformation sequence.

    Advised Approach:
    1. Run BFS, we are looking for shortest path. On an undirected unweighted graph, BFS will always find it.
    2. 2 approaches to mapping words to the graph:
        a. Don't scan wordList looking for words a char difference, invert/flip that question.
            For the current word, generate every mutation (pos * 'a'.'z'), checking an unordered_set if it exists
        b. bucketing - 'h*t' for each word and each position i, 
            build the key word with word[i] = '*', and store key → list of words, words are neighbour if they 
            share a key
    
    So the idea currently:
    0. push back all the words into an unordered_set
    1. push beginWord onto stack and start BFS
    2. in the inner loop, attempt to generate the next word, (if none exist then it'll give us the wrong result)
    3. continue iteration until complete - updating result ctr as we progress

    There are however conceptually 3 approahces:
     1. Compare every pair of words to identify neighbours. (bruteforce)
     2. Group words using wildcard patterns. (adj list)
     3. Generate one-char mutations and heck dictionary membership

*/
public:

    int ladderLength(
        string beginWord, 
        string endWord, 
        vector<string>& words
    ) 
    {
        // 0.
        std::unordered_set< string > neighbours;
        for( const auto& w : words )
            neighbours.insert( w );

        // 1.
        std::queue< string > q;
        int result = 1;

        q.push( beginWord );
        neighbours.erase( beginWord );

        while( !q.empty() )
        {

            int count = q.size();
            while ( count-- )
            {
                string cur = q.front(); q.pop();

                if ( cur == endWord )
                    return result;

                // 2. Generate neighbours
                for( int i = 0; i < cur.size(); ++i )
                {
                    string copy = cur;
                    for( int j = 0; j < 26; ++j )
                    {
                        copy[ i ] = 'a' + j;
                        if ( neighbours.erase( copy ) )
                            q.push( copy );
                        
                    }
                }
            }

            ++result;
        }

        return 0;
    }
};
