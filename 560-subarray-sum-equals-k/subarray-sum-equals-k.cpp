class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l =0;
        int r =0;
        int total =0;
        for(int i =0;i<nums.size();i++){
            int sum =0;
            for(int j =i;j<nums.size();j++){
              sum += nums[j];
              if(sum == k){
                total++;
              }  
            }
        }
        return total;
    }
};