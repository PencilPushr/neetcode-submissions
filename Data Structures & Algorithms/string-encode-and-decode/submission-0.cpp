class Solution {
public:

    string encode(vector<string>& strs) {
        string ret_result = "";

        if (strs.size() == 0) return ret_result;


        for (int i = 0; i < strs.size(); ++i)
        {
            ret_result += std::to_string(strs[i].size()) + "#" + strs[i];
        }

        return ret_result;
    }

    vector<string> decode(string s) 
    {
        vector<string> ret_result;
        size_t length = 0;
        int position = 0;
        
        while (position < s.size())
        {
            length = 0;
            while (isdigit(s[position]))
            {
                length = length * 10 + (s[position++] - '0');
            }

            if (s[position++] != '#')
            {
                //throw an error
            }

            std::string result = s.substr(position, length);
            position += length;

            ret_result.emplace_back(result);
        }
        return ret_result;
    }
};
