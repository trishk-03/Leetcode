class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {        
        unordered_map<int,int> mp;

        for(int i =0;i<nums.size();i++){
           mp[nums[i]]++;
        }

        int size = nums.size()/2;
 
        for(auto it :mp){
            if(it.second == size)
            return it.first;
        }

        return -1;    
    }
};