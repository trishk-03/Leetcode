class Solution_mine {
public:
    int maxVowels(string s, int k) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int count = 0;
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
        while (r < s.length()) {
            if (set.find(s[r]) != set.end()) {
                count++;
            }
            if (r - l + 1 > k) {
                if (set.find(s[l]) != set.end()) {
                    count--;
                }
                l++;
            }
            maxlen = max(maxlen, count);
            r++;
        }
        return maxlen;
    }
};

class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int result = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i]))
                count++;
        }
        result = count;

        // Slide the window
        for (int i = k; i < s.length(); i++) {
            if (vowels.count(s[i]))
                count++; // add new char
            if (vowels.count(s[i - k]))
                count--; // remove old char
            result = max(result, count);
        }

        return result;
    }
};
