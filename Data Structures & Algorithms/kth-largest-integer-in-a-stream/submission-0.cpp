class KthLargest 
{
public:
    std::size_t m_k;
    std::priority_queue< int, vector<int>, greater<int>> m_pq; // Min heap

    KthLargest(int k, vector<int>& nums) 
    {
        m_k = k;
        for( auto& i : nums )
            add( i ); // Maintain K elements in heap
    }
    
    int add(int val) 
    {
        m_pq.push( val );

        while( m_pq.size() > m_k ) // Remove elements that violate our K property
            m_pq.pop();

        return m_pq.top();
    }
};
