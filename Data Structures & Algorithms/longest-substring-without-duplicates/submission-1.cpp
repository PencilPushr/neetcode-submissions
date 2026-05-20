class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
         unordered_map<char, int> charIndex; // Stores: char -> last seen index
        int maxLength = 0;
        int l = 0;  // Left boundary of window
        
        // Right pointer explores the string
        for (int r = 0; r < s.length(); r++) 
        {
            char currentChar = s[r];
            
            // If character exists in window, move l pointer
            // to position AFTER the last occurrence
            if (charIndex.find(currentChar) != charIndex.end()) 
            {
                l = max(l , charIndex[currentChar] + 1);
            }
            
            // Update the character's position
            charIndex[currentChar] = r;
            
            // Calculate window size and update max
            maxLength = max(maxLength, r - l + 1);
        }
        
        return maxLength;
    }
};
