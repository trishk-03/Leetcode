class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // store frequency of s1
        for(char ch : s1) {
            freq1[ch - 'a']++;
        }

        int k = s1.length();

        for(int i = 0; i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;

            // maintain window size
            if(i >= k) {
                freq2[s2[i - k] - 'a']--;
            }

            if(freq1 == freq2) return true;
        }

        return false;
    }
};