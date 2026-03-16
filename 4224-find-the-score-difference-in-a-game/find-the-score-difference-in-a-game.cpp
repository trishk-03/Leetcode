class Solution {
public:
    int scoreDifference(vector<int>& nums) {
     int fp =0;
     int sp =0;
     bool act = true;

     for(int i =0;i<nums.size();i++){
       if(nums[i]% 2 != 0)
       act = !act;

       if((i+1)% 6 ==0 )
       act = !act;

       if(act) fp += nums[i];
       else sp += nums[i]; 
    }
    return fp-sp;   
    }
};