class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlen =0;
        int r =0;
        int l =0;
        int k = maxCost;

        while(r<s.size()){
            int diff = abs(s[r]-t[r]);

            k -= diff;

            while(k<0){
                k += abs(s[l]-t[l]);
                l++;
            }

            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};