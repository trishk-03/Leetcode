class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0; int r=0; int maxlen =0;
        set<char> set;

        while(r<s.size()){
          if(set.find(s[r]) == set.end()){
            set.insert(s[r]);
            // maxlen++;
            maxlen =max( maxlen , r-l+1);
            r++;
          }
          else{
            set.erase(s[l]);
            l++;
          }
        } 
        return maxlen;
    }
};