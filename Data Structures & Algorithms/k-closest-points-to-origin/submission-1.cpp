class Solution {
public:

    struct CustomComparator 
    {
        bool operator()(const vector<int>& a, const vector<int>& b) const 
        {
            long long distA = 1LL * a[0] * a[0] + 1LL * a[1] * a[1];
            long long distB = 1LL * b[0] * b[0] + 1LL * b[1] * b[1];
            return distA > distB; // Note: min-heap by default
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        std::priority_queue< 
            vector< int >, 
            vector< vector< int >>, 
            CustomComparator
        > pq(
            points.begin(),
            points.end()
        );

        std::vector< std::vector< int >> result;

        while( result.size() < k )
        {
            result.push_back( pq.top() ); 
            pq.pop();
        }

        return result;
    }
};
