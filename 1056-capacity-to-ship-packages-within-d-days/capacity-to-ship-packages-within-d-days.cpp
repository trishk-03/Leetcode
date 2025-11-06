class Solution {
private:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int dayCount = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w > capacity) {
                dayCount++;
                load = w;

                if (dayCount > days)
                    return false;
            } else {
                load += w;
            }
        }
        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid; // mid capacity works → try smaller
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }

        return ans;
    }
};
