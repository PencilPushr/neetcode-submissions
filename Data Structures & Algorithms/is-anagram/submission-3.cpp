class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // If sizes don't match or either of the strings are null
        if ( s.length() != t.length() ) return false;

        std::unordered_map<char, int> bucket;

        // If we see a char in s, increment, and if it appears in t decrement
        // by the end all of the chars should be 0 in bucket
        for( int i = 0; i < s.length(); i++ )
        {
            bucket[s[i]]++;
            bucket[t[i]]--;
        }

        // Iterate over the map, checking if every character is 0
        for (const auto& c : bucket)
        {
            if ( c.second != 0 ) return false;
        }

        return true;
    }
};
