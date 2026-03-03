class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string ans = s + s;

        for (int i = 0; i < s.size(); i++) {
            int j = 0;
            while (j < goal.size() && ans[i + j] == goal[j]) {
                j++;
            }
            if (j == goal.size()) return true;
        }

        return false;
    }
};