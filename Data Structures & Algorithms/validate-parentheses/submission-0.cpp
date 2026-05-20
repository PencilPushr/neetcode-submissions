class Solution {
public:
    bool isValid(string s) 
    {
        int n = s.size();
        stack<char> st;

        char c;
        for (int i = 0; i < n; i++)
        {
            c = s[i];
            if (c == '(')
                st.push(')');
            else if (c == '{')
                st.push('}');
            else if (c == '[')
                st.push(']');
            else if (st.empty() || st.top() != c)
                return false;
                else
                st.pop();  // Add this line
        }
        return st.empty();
    }
};
