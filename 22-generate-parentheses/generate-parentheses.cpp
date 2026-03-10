class Solution {
private:
bool isvalid(string &s){
    int count = 0;

    for(char c : s){
        if(c == '(') count++;
        else count--;

        if(count < 0) return false;
    }
    if(count == 0) return true;
    return false;
}
   void rec(vector<string> &ans, int pair ,string s){
    if(s.length()== pair) {
        if(isvalid(s))
        ans.push_back(s);
        return;
    }
    s += '(';
    rec(ans,pair,s);
    s.pop_back();
    s+= ')';
    rec(ans,pair,s);
    s.pop_back();
   }
public:
    vector<string> generateParenthesis(int n) {
      vector<string> ans;
      string s ="";
      rec(ans, 2*n , s);
      return ans;  
    }
};