class Solution {
private:
    void combine(vector<vector<int>>&ans, int index,int sum, int k , int &n,vector<int> temp){
        if(sum > n || k<temp.size()) return;

        if( sum == n && temp.size()==k){
         ans.push_back(temp);
         return;
        }
        for(int i =index; i<10;i++){
          temp.push_back(i);
          combine(ans, i+1, sum+i,k,n,temp);
          temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
     vector<vector<int>> ans;
     vector<int> temp;
     combine(ans,1,0,k,n,temp);  
     return ans; 
    }
};