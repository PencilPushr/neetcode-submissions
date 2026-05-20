class TimeMap {
public:
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        umap[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) 
    {
        std::vector<pair<string, int>>& values = umap[key];
        int l = 0;
        int r = values.size() - 1;
        string result = "";  // Default value if no valid timestamp is found

        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (values[m].second <= timestamp)
            {
                result = values[m].first; // Update result to the current candidate
                l = m + 1;               // Look for a closer timestamp on the right
            }
            else
            {
                r = m - 1;               // Look for a valid timestamp on the left
            }
        }
        return result;
    }

private:
    std::unordered_map<string, vector<pair<string, int>>> umap; 

};
