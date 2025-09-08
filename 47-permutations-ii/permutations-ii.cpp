class Solution {
public:
    void rec_permute(vector<int>&nums, set<vector<int>>& ans, int index){
        if(index == nums.size()){
            ans.insert(nums);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            rec_permute(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
        
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        int index = 0;
        rec_permute(nums,ans,index);     
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};