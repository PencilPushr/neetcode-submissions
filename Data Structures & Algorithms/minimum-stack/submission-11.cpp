class MinStack {
public:
    std::vector<int> m_vStack;
    std::stack<int> m_stMin;

    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        m_vStack.push_back(val);
        val = std::min(val, m_stMin.empty() ? val : m_stMin.top());
        m_stMin.push(val);
    }
    
    void pop() 
    {
        m_vStack.pop_back();
        m_stMin.pop();
    }
    
    int top() 
    {
        return m_vStack.back();
    }
    
    int getMin() 
    {
        return m_stMin.top(); 
    }
};
