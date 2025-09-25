class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        //  Find min and max positions
        int min_position = 0, max_position = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[min_position])
                min_position = i;
            if (nums[i] > nums[max_position])
                max_position = i;
        }

        if (min_position > max_position)
            swap(min_position, max_position);

        //  Three possible ways
        int deleteFromFront = max_position + 1; // Remove both from front
        int deleteFromBack = n - min_position;  // Remove both from back
        int deleteFromBoth =
            (min_position + 1) +
            (n - max_position); // Min from front, Max from back

        // Return minimum
        return min({deleteFromFront, deleteFromBack, deleteFromBoth});
    }
};
