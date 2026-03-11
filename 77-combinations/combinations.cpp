class Solution {
private:
   void solve(vector<vector<int>> &result, vector<int> &ans, int &n,int &k,int idx ){
    if(ans.size()==k){
        result.push_back(ans);
        return;
    }
    if(idx > n) return;

    ans.push_back(idx);
    solve(result,ans,n,k,idx+1);
    ans.pop_back();
    solve(result,ans,n,k,idx+1);
    return;
   }
public:
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> result;
       vector<int> ans;
       solve(result, ans, n, k, 1);
       return result;
    }
};