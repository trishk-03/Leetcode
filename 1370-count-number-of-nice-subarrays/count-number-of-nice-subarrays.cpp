class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {

            sum += (nums[r] % 2);

            while (sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }

            if (sum == k) {
                int temp = l;
              
                while (temp <= r && nums[temp] % 2 == 0) {
                    count++;
                    temp++;
                }

                count++;
            }
        }

        return count;
    }
};
