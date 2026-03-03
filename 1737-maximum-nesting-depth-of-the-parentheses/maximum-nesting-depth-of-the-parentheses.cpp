class Solution {
public:
    int maxDepth(string s) {
      int left =0;
      int right = 0;
      int maxlen =0;

      for(int i=0;i<s.length();i++){
        if(s[i]== '(') left ++;
        if(s[i] == ')') right --;

        maxlen = max(maxlen, left+right);
      } 
      return maxlen;
    }
};