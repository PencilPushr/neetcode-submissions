class Solution {
public:

/*

vector<int> countBits(int n) 
    {
        std::vector<int> vRes = {};

        int iBitCount = sizeof(n) * 8;

        vRes[0] = 0;

        for(int i = 1; i < iBitCount; ++i )
        {
            
            // Somehow count the number of bits we have now encountered

            vRes[i].push_back();
        }
        
    }
    */

    vector<int> countBits(int n) 
    {
        std::vector<int> vRes;

        //int iBitCount = sizeof(n) * 8;

        vRes.push_back(0);

        for(int i = 1; i <= n; ++i )
        {
            
            // Count the number of bits as the current representation 
            // place them back into the array
            int iCurNumBits = __builtin_popcount(i);
            vRes.push_back( iCurNumBits );
        }
        
        return vRes;
    }
};
