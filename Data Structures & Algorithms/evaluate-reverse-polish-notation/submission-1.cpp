class Solution {
public:
    int evalRPN( vector<string>& tokens ) 
    {

        std::stack<int> st;

        for( const string& token : tokens )
        {
            if (token == "+" || token == "-" || token == "*" || token == "/") 
            {
                // Pop two operands (order matters for - and /)
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push((double)(a / b));
            } 
            else 
            {
                // It's a number, push it
                st.push(stoi(token));
            }
            
        }

        return st.top();

    }
};
