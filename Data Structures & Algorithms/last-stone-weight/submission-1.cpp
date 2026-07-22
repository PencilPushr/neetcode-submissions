class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        std::priority_queue< int > pq( stones.begin(), stones.end() );

        while( pq.size() > 1 )
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            if ( x > y )
                pq.push( x - y );

            if ( x < y )
                pq.push( y - x ); 

            if ( x == y )
                pq.push( 0 );
        }
        
        return pq.top();
    }
};
