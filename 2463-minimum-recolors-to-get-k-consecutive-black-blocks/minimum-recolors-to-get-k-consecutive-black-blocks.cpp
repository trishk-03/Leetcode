class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int l = 0;              // Left pointer (start of window)
        int r = 0;              // Right pointer (end of window)
        int whiteCount = 0;     // Count of 'W' in current window
        int minSteps = INT_MAX; // Store minimum recolors needed

        // Expand the right pointer until we have a window of size k
        while (r < n) {
            // If the current right character is 'W', count it
            if (blocks[r] == 'W')
                whiteCount++;

            // If our window size exceeds k, shrink from the left
            if (r - l + 1 > k) {
                if (blocks[l] == 'W')
                    whiteCount--; // Remove left block effect
                l++;              // Move left pointer forward
            }

            // If we have a valid window of size exactly k, check minimum
            if (r - l + 1 == k) {
                minSteps = min(minSteps, whiteCount);
            }

            // Move right pointer forward
            r++;
        }

        return minSteps;
    }
};

// Approach 2
class Solution2 { 
    public: 
    int minimumRecolors(string blocks, int k) { 
        int white=0; 
        for(int i =0; i<k;i++){ 
            if(blocks[i]== 'W') white++; } 
        int minsteps = white; 
        for(int i=k;i<blocks.size();i++){ 
            if(blocks[i]== 'W') white++; 
            if(blocks[i-k]=='W') white--; 
            minsteps = min(minsteps, white); 
        } 
        return minsteps; 
    } 
};