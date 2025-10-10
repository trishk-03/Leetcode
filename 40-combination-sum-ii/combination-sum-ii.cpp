class Solution {
private:
   void combine(vector<int>&candidates, vector<vector<int>>&answer, vector<int> &curr_arr,int index, int target){
    
    if(target== 0){
        answer.push_back(curr_arr);
        return;
    } 
    for(int i =index; i<candidates.size();i++){
        if( i>index &&candidates[i] == candidates[i-1])
        continue;
    if (candidates[i] > target) break; // if a current index element is larger than target value       stop the recuursion further for exploration 
    curr_arr.push_back(candidates[i]);
    combine(candidates, answer,curr_arr, i+1, target-candidates[i]);
    curr_arr.pop_back();
        
    }

   }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>answer;
        vector<int> curr_arr;
        sort(candidates.begin(), candidates.end());
        combine(candidates, answer, curr_arr, 0, target);
        return answer;
    }
};