class Solution {
public:
/*
    First idea is to collect all seperate characters via a setmap.
    This will give the number of different kinds of tasks and their frequency

    We can then have a map of { A : 3 }



*/
    int leastInterval(vector<char>& tasks, int n) 
    {
        // 1. Build up freq
        std::unordered_map< char, int > mapFreq;

        for( const auto& t : tasks )
            ++mapFreq[ t ];

        // 2. Fill up maxHeap based on count?
        /*
                    A : 3
                  /      \
                B : 1    C : 1
        */

        std::priority_queue< int > pq;

        for (const auto& [ch, count] : mapFreq)
            pq.push(count);

        // 3. Run tasks and push onto queue, cannot run task again until other tasks have run?
        int time = 0;
        std::queue<std::pair<int,int>> cooldown;  // {remaining_count, wake_up_time}
        
        // 4. Push tasks between cooldown and heap to get the next available task to run
        while( !pq.empty() || !cooldown.empty() )
        {
            ++time;
            if ( !pq.empty() )
            {
                int count = pq.top() - 1; pq.pop();
                
                if (count > 0) 
                    cooldown.push({count, time + n});
                
            }

            if ( !cooldown.empty() && cooldown.front().second == time )
            {
                pq.push( cooldown.front().first ); cooldown.pop();
            }
        }

        return time;
    }
};
