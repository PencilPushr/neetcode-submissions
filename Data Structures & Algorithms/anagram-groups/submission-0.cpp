class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> ans;

        if (strs.empty()) return {{}};

        for (auto& s : strs)
        {
            vector<int> count(26, 0);
            
            for (char c : s) 
            {
                count[c - 'a']++;
            }

            std::string key;
            for (int i = 0; i < 26; i++) 
            {
                if (count[i] > 0) 
                {   // TEA becomes 1a1e1t, we append count then the letter.
                    key += std::to_string(count[i]) + (char)('a' + i);
                }
            }

            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : ans) {
            result.push_back(pair.second);
        }

        return result;
    }
};
