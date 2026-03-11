class Solution {
private:
    void solve(vector<int> &nums, int target, int &sum, int &result, int idx){
        if(idx == nums.size()){
            if(sum == target) result++;
            return;
        }

        // choose +
        sum += nums[idx];
        solve(nums, target, sum, result, idx + 1);
        sum -= nums[idx];   // backtrack

        // choose -
        sum -= nums[idx];
        solve(nums, target, sum, result, idx + 1);
        sum += nums[idx];   // backtrack
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int result = 0;
        int sum = 0;
        solve(nums, target, sum, result, 0);
        return result;
    }
};