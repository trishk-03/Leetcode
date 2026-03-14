class Solution {
private:
    void solve(vector<string> &result, string ans, string &s, int idx, int parts){
        
        // If 4 parts formed and string is fully used
        if(parts == 4 && idx == s.length()){
            ans.pop_back(); // remove last dot
            result.push_back(ans);
            return;
        }

        // If too many parts or string finished early
        if(parts == 4 || idx == s.length()) return;

        for(int len = 1; len <= 3 && idx + len <= s.length(); len++){

            string sub = s.substr(idx, len);

            // leading zero check
            if(sub.length() > 1 && sub[0] == '0') continue;

            int num = stoi(sub);

            if(num <= 255){
                solve(result, ans + sub + ".", s, idx + len, parts + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        solve(result, "", s, 0, 0);
        return result;
    }
};