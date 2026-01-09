class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

class BruteForce {
public:
    void rotate(vector<int>& nums, int k) {
       while(k){
       for(int j = nums.size()-1; j>0;j--){
        swap(nums[j],nums[j-1]);
       }
       k--;
       } 
    }
};