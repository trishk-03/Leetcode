class Solution {
private:
    int sum(vector<int>& nums, int mid){
        int s =0;
        for(auto n: nums){
            s += (n + mid - 1) / mid;  // ceil(n/divisor)
        }
        return s;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; 
        int high = *max_element(nums.begin(), nums.end());
        int ans =-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;

            if(sum(nums,mid)<=threshold){
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return ans;
    }
};