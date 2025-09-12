class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
           int l =0; int r =0;
           int minLen =INT_MAX;
           int sum =0;
           while(r< nums.size()){
            sum += nums[r];

            while (sum >= target) {
            minLen = min(minLen, r - l + 1);
            sum -= nums[l];
            l++;
            }
            r++;
           }
           if(minLen == INT_MAX)
            return 0; 
           else
            return minLen;     
    }
};