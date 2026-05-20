class Solution {
public:
    bool isValid(string s) 
    {
        std::stack<char> stack;

        for ( char& c : s )
        {
            if ( c == '(' )
                stack.push(')');
            else if ( c == '{' )
                stack.push('}');
            else if ( c == '[' )
                stack.push(']');
            else if ( !stack.empty() && stack.top() == c )
                stack.pop();
            else
                return false;
        }

        return stack.empty();
    }
};
