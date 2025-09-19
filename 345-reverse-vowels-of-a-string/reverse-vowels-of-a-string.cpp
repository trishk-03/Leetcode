class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() - 1;
        set<char> vowel = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

        while (start < end) {
            while (start < end && vowel.find(s[start]) == vowel.end()) {
                start++;
            }
            while (start < end && vowel.find(s[end]) == vowel.end()) {
                end--;
            }
            if (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        } return s;
    }
};    