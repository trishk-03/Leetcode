class Solution {
public:
    int scoreOfString(string s) {
        int result =0;
        for(int i =0; i< s.size()-1;i++){
            int first = (s[i]-'a');
            int second =(s[i+1]-'a');
            int ans = abs(first - second);
            result+= ans;
        }
        return result;
    }
};