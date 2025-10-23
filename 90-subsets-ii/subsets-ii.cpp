class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>> & result, set<vector<int>> &s, vector<int> ans, int index){
        if(index==nums.size()){
            if(s.find(ans)== s.end()){
                s.insert(ans);
                result.push_back(ans);
            }
            return;
        }

        ans.push_back(nums[index]);
        solve(nums,result,s,ans,index+1);
        ans.pop_back();
        solve(nums,result,s,ans,index+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        solve(nums, result,s, ans, 0);
        return result;
    }
};