class Solution {
public:
    string removeOuterParentheses(string s) {
        string result ="";
        int lvl =0;
        for(int i =0;i<s.length();i++){
            if(s[i]=='(') {
                if(lvl>0) result += s[i];
                lvl++;
            }
            else if(s[i] ==')'){
                lvl--;
                if(lvl>0) result += s[i];
            }
        }

        return result;
    }
};