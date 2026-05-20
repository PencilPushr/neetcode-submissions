class MinStack {
public:
    MinStack() 
    {
    }
    
    void push(int val) 
    {
        m_stack.emplace_back(val);
        val = std::min(val, m_min.empty() ? val : m_min.back());
        m_min.emplace_back(val);
    }
    
    void pop() 
    {
        m_stack.pop_back();
        m_min.pop_back();
    }
    
    int top() 
    {

        return m_stack.back();
    }
    
    int getMin() 
    {

        return m_min.back();
    }

private:
    std::vector<int> m_stack;
    std::vector<int> m_min;
};
