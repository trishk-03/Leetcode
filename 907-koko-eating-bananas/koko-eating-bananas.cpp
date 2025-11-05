class Solution {
private:
    int findmax(vector<int> &piles){
        int mx = INT_MIN;
        for(int i =0; i<piles.size();i++){
            if(piles[i]>mx) mx = piles[i];
        }
        return mx;
    }
    long long total(vector<int> & piles ,int mid){
        long long total_hours=0;
        for(int i =0;i<piles.size();i++){
            total_hours += ceil((double)piles[i]/mid);
            // total_hours +=(piles[i] + mid - 1) / mid;
        }
        return total_hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);

        int ans = INT_MAX;

        while(low<= high){

            int mid = low +(high-low)/2;

            long long total_hours = total(piles, mid);

            if(total_hours <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};