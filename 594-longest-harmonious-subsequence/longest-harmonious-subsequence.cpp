class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int num : nums)
            freq[num]++;

        int maxLen = 0;

        for(auto &p : freq){
            int key = p.first;

            if(freq.count(key + 1)){
                maxLen = max(maxLen, freq[key] + freq[key+1]);
            }
        }

        return maxLen;
    }
};