class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        vector<int> freq(26, 0);

        int distinct = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            if (++freq[s[r] - 'a'] == 1) {
                distinct++;
            }

            // Keep window size exactly minSize
            if (r - l + 1 > minSize) {
                if (--freq[s[l] - 'a'] == 0) {
                    distinct--;
                }
                l++;
            }

            // Now window size == minSize
            if (r - l + 1 == minSize) {
                if (distinct <= maxLetters) {
                    string sub = s.substr(l, minSize);
                    mp[sub]++;
                }
            }
        }
        int maxlen =0;
        for( auto&  i: mp){
            maxlen = max(maxlen,i.second);
        }
        return maxlen;
    }
};