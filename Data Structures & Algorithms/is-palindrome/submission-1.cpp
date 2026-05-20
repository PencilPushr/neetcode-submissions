class Solution {
public:
    bool isPalindrome(string s) 
    {
        int lhs, rhs;

        lhs = 0;
        rhs = s.size()-1;

        if (s.empty()) return true;
        

        while ( lhs <= rhs )
        {
            while (!isalnum(s[lhs]) && lhs < rhs)
            {
                lhs++;
            }
            while (!std::isalnum(s[rhs]) && lhs < rhs)
            {
                rhs--;
            }
            if (std::tolower(s[lhs]) != std::tolower(s[rhs])) {
                return false;
            }
            lhs++;
            rhs--;
        }
    }
};
