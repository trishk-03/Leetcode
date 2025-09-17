class Solution_1 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
        return true;
        return false;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> freq (256,0);
       if(s.size()!= t.size()) return false;
       for(int i =0; i<s.size();i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
       }
       for(int i =0;i<freq.size();i++){
        if(freq[i]!=0) return false;
       }

       return true;

       
    }
};
