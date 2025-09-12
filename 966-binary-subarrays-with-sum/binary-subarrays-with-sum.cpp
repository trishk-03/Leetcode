class Solution {
public:
    int countSubarraysWithSumAtMost(vector<int>& nums, int goal){
        int l = 0, sum = 0, count = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(l <= r && sum > goal){
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1); 
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal < 0) return 0; 
        return countSubarraysWithSumAtMost(nums, goal) - 
               countSubarraysWithSumAtMost(nums, goal - 1);
    }
};
