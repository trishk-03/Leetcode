class Solution {
public:
    bool canJump(vector<int>& nums) {

        int max_val =0;
        for(int i =0;i<nums.size();i++){
            if(i>max_val) return false;

        max_val = max(max_val,i+nums[i]);
        }
        return true;
    }
};