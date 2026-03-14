class Solution {
private:
    void solve(int n, vector<string> &result, string &s){
        
        if(s.length() == n){
            result.push_back(s);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            
            if(!s.empty() && s.back() == ch)
                continue;

            s.push_back(ch);

            solve(n, result, s);

            s.pop_back();
        }
    }

public:
    string getHappyString(int n, int k) {

        vector<string> result;
        string s = "";

        solve(n, result, s);

        if(result.size() < k)
            return "";

        return result[k-1];
    }
};