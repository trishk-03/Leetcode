class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // optimal solution
        vector<int> ans(nums.size(),0);
        int p =0, n=1;

        for(int i =0;i<nums.size();i++){
            if(nums[i]>0){
                ans[p]= nums[i];
                p = p+2;
            }
            else{
                ans[n]= nums[i];
                n= n+2;
            }
        }
        return ans;
    }
};

        // brute force 
        // vector<int>a;
        // vector<int>b;
        // for(int i =0;i<nums.size();i++){
        //     if(nums[i]>0){
        //         a.push_back(nums[i]);
        //     }
        //     else{
        //         b.push_back(nums[i]);
        //     }
        // }

        // vector<int> ans;
        // for(int i =0;i<a.size();i++){
        //     ans.push_back(a[i]);
        //     ans.push_back(b[i]);
        // }
        // return ans;