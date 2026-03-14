class Solution {
public:
    int longestContinuousSubstring(string s) {
      int curr =1;
      int maxlen =1;

      for(int i =1;i<s.length();i++){
        if(s[i]-s[i-1] == 1)
        curr++;
        else
        curr = 1;

        maxlen = max(curr,maxlen);
      }
      return maxlen;  
    }
};