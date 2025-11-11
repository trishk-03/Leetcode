class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int product = 1;
        int l = 0;
        int result = 0;

        for (int r = 0; r < nums.size(); r++) {
            product *= nums[r];

            while (product >= k && l <= r) {
                product /= nums[l];
                l++;
            }

            result += (r - l + 1);
        }

        return result;
    }
};
