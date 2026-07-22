class MedianFinder {
public:
    MedianFinder() 
    {}
    
    void addNum(int num) 
    {
        m_pq.push( num );    
    }
    
    double findMedian() 
    {
        printf("New iter:\n");

        int n = m_pq.size();
        auto copy = m_pq;

        double a = 0, b = 0;

        // For n = 2 (even), we need to pop 2 elements to get both midpoints.
        // For n = 1 (odd), we need to pop 1 element to get the single midpoint.
        int targetRemainingSize = n / 2 - (n % 2 == 0 ? 1 : 0);

        printf("\t");
        while( copy.size() > targetRemainingSize )
        {
            b = a;
            a = copy.top(); copy.pop();
            printf("%f ", a );
        }
        printf("\n");

        if ( n % 2 == 0 ) // Even length
        {
            return (double) ( a + b ) / 2;
        }
        else
        {
            return a;
        }
    }

private:

    std::priority_queue< double > m_pq;

};
