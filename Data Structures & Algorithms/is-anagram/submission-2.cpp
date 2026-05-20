class Solution {
public:
    bool isAnagram(string s, string t) 
    {
       if (s.length() != t.length()) return false;

       std::unordered_map<char, int> bucket;

       for(int i = 0; i < s.length(); i++)
       {
            bucket[s[i]]++;
            bucket[t[i]]--;
       }

       for (const auto& c : bucket)
       {
            if (c.second != 0) return false;
       }

       return true;
    }
};
