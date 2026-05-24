class Solution {
public:

/*

two ideas:
1. use set and two pointers, left pointer is always implicitly 0, right pointer is the 
    end of the common prefix
2. precompute the first word - use this as -> { "", "b", "ba", "bat" }

*/

    string longestCommonPrefix(vector<string>& strs) 
    {
        std::string prefix;

        prefix = strs[0];


        for( int i = 1; i < strs.size(); ++i )
        {
            int prefixEnd = 0;

            while( 
                prefixEnd < prefix.size()
                && prefixEnd < strs[i].size()
                && prefix[prefixEnd] == strs[i][prefixEnd]
            )
            {
                prefixEnd++;
            }

            if ( prefixEnd == 0 )
                return "";

            prefix = prefix.substr( 0, prefixEnd );
        }

        return prefix;
    }
};