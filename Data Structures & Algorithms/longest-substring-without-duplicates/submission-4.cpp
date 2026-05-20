class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0;
        int r = 0;

        if (s.size() == 1) return 1;

        unordered_set<char> chars;
        int maxLen = 0;

        while (r < s.size())
        {
            while (chars.find(s[r]) != chars.end())
            {
                chars.erase(s[l]);
                l++;
            }
            chars.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
