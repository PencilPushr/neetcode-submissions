class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> bucket;

        if (s.length() != t.length()) return false;

        for(int i = 0; i < s.length(); ++i)
        {
            bucket[s[i]]++;
            bucket[t[i]]--;
        }
        
        for (auto& it : bucket) {
            //check if the second value in the keyvalue pair contains a value other than 0
            //e.g. std::pair<first, second>
            if (it.second){ //resulting boolean should be not be true;
            return false;
            }
        }
        return true;
    }
};
