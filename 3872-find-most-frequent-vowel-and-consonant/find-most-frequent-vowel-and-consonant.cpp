class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        int maxVowel = 0, maxConsonant = 0;

        auto isVowel = [](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };

        for (char c : s) {
            int idx = c - 'a';
            freq[idx]++;

            if (isVowel(c))
                maxVowel = max(maxVowel, freq[idx]);
            else
                maxConsonant = max(maxConsonant, freq[idx]);
        }

        return maxVowel + maxConsonant;
    }
};
