class Solution {
public:

    std::string CreateKey(std::string& input)
    {
        std::vector<int> count(26, 0);

        for (char& c : input)
        {
            count[c - 'a']++;
        }

        std::string key;

        for (int i = 0; i < count.size(); i++)
        {
            // TEA becomes 1a1e1t, we append count then the letter.
            if (count[i] > 0)
                key += std::to_string(count[i]) + (char)('a' + i); 
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        std::unordered_map<std::string, vector<std::string>> groups;

        for (auto& str : strs)
        {
            std::string key = CreateKey(str);

            groups[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& vkpair : groups)
        {
            result.push_back(vkpair.second);
        }
        
        return result;
    }
};
