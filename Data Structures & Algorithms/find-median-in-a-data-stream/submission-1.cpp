class MedianFinder {
public:
    MedianFinder() 
    {}
    
    void addNum(int num) 
    {
        // 1. Add to smaller half ( max heap )
        small.push( num );

        // 2. Make sure every element in 'smaller' is <= 'large' half
        if ( 
            !small.empty() && 
            !large.empty() && 
            small.top() > large.top()
        )
        {
            large.push( small.top() );
            small.pop();
        }

        // 3. Keep sizes balanced ( small can have at most 1 more element than large )
        if ( small.size() > large.size() + 1 ) // Small is too big
        {
            large.push( small.top() );
            small.pop();
        }
        else if ( small.size() < large.size() ) // Large is too big
        {
            small.push( large.top() );
            large.pop();
        }
    }
    
    double findMedian() 
    {
        if ( ( small.size() + large.size() ) % 2 )
        {
            return small.top();
        }
        else
        {
            return ( small.top() + large.top() ) / 2.0;
        }
    }

private:

    std::priority_queue< double > small;
    std::priority_queue< double, vector<double>, std::greater<>> large;

};
