class Solution {

private:
    void combine(vector<int>& candidates, vector<vector<int>> &answer, vector<int>&curr_arr,  int index, int target){
        if(index>candidates.size()-1 || target<0 ) return ;
        if(target == 0) {
            answer.push_back(curr_arr);
            return;
        }
        curr_arr.push_back(candidates[index]);
        combine(candidates, answer, curr_arr, index, target-candidates[index]);
        curr_arr.pop_back();
        combine(candidates, answer , curr_arr , index +1, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>> answer;
     vector<int> curr_arr;
     int index =0;
     combine(candidates, answer, curr_arr, index, target);   
     return answer;
    }
};