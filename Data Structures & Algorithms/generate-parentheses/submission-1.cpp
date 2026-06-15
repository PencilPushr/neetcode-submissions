class Solution {
public:
/*

    I used to believe that having openCount and closeCount in one counter would be better, but it's not

    Having an open and close lets you branch specifically down the BDT as needed with finer control.

    The idea is pretty simple, similar to subsets.

    You either:
        - open
        - close

    Binary decision means binary decision tree should be built and can pretty easily recurse.

    The issue lies in, we must start with a ( to begin with, and we cannot end on a close or open count greater
    than the other.

    So by the end, open == close.

    1. Base case, open == close && curGen.size() == n * 2 (as it is a pair of () not just 1)
    2. if: open < n we can open, e.g. open < 3, we can have at max, 3
    3. if close < open, initially I had used this as n, but this won't work:
        a. What happens if we have close > open? 1 > 2? Well we have "())".
            No amount of opens will fix this. So we have to clamp down on how many opens have happened so far

*/

    vector< string > g_result;

    vector<string> generateParenthesis(int n) 
    {
        string current = "";
        build(n, current, 0, 0);
        return g_result;
    }
    
private:
    void build(
        int n,
        string& current, 
        int openCount, 
        int closeCount
    ) 
    {
        // 1. Base case
        if ( current.length() == (n * 2) && openCount == closeCount)
        {
            g_result.push_back( current );
            return;
        }

        if ( openCount < n )
        {
            current.push_back( '(' );
            build( n, current, openCount + 1, closeCount );
            current.pop_back();
        }

        if ( closeCount < openCount )
        {
            current.push_back( ')' );
            build( n, current, openCount, closeCount + 1 );
            current.pop_back();
        }

        return;
    }
};
