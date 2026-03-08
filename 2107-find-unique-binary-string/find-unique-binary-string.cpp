class Solution {
private:
    string generate(int size, int index, string &ans, unordered_set<string> &st){
        
        if(index == size){
            if(st.find(ans) == st.end())
                return ans;
            return "";
        }

        ans.push_back('0');
        string res = generate(size, index+1, ans, st);
        if(res != "") return res;
        ans.pop_back();

        ans.push_back('1');
        res = generate(size, index+1, ans, st);
        if(res != "") return res;
        ans.pop_back();

        return "";
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_set<string> st(nums.begin(), nums.end());

        int size = nums[0].length();
        string ans = "";

        return generate(size,0,ans,st);
    }
};