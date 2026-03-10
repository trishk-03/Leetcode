class Solution {
public:
    void solve(vector<string>& ans, string num, int target, int idx,
               long long value, long long prev, string path) {
        
        if(idx == num.size()){
            if(value == target)
                ans.push_back(path);
            return;
        }

        for(int i = idx; i < num.size(); i++){

            if(i != idx && num[idx] == '0') break;

            string part = num.substr(idx, i - idx + 1);
            long long curr = stoll(part);

            if(idx == 0){
                solve(ans, num, target, i+1, curr, curr, part);
            }
            else{

                solve(ans, num, target, i+1,
                      value + curr,
                      curr,
                      path + "+" + part);

                solve(ans, num, target, i+1,
                      value - curr,
                      -curr,
                      path + "-" + part);

                solve(ans, num, target, i+1,
                      value - prev + prev*curr,
                      prev*curr,
                      path + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(ans, num, target, 0, 0, 0, "");
        return ans;
    }
};