class Solution {
private:
    bool inc(vector<int>& a, int l, int r) {
    for (int i = l; i < r; i++)
        if (a[i] >= a[i+1]) return false;
    return true;
}

    bool dec(vector<int>& a, int l, int r) {
        for (int i = l; i < r; i++)
            if (a[i] <= a[i+1]) return false;
    return true;
}

public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        for (int i = 1; i <= n - 3; i++) {
            for (int j = i + 1; j <= n - 2; j++) {
                if (inc(nums, 0, i) &&
                    dec(nums, i, j) &&
                    inc(nums, j, n - 1))
                    return true;
            }
        }
        return false;
    }

};