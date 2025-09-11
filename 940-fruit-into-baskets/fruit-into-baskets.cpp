class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        int maxlen = 0;
        unordered_map<int,int> count;

        while (r < (int)fruits.size()) {
            count[fruits[r]]++;
            while (count.size() > 2) {
                count[fruits[l]]--;
                if (count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
