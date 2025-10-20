class Solution {
private:
   void solve(vector<int> & nums, vector<vector<int> >& result, vector<int> ans, int index){
    if(index== nums.size()){
        result.push_back(ans);
        return;
    }
    solve(nums,result,ans,index+1);

    ans.push_back(nums[index]);
    solve(nums,result,ans,index+1);
   }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        int index =0;
        solve(nums,result,ans,index);
        return result;
    }
};