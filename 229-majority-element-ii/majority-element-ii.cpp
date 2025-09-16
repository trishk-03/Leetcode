class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size() / 3;
        vector<int> v;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        for (auto& it : m) {
            if (it.second > size) {
                v.push_back(it.first);
            }
        }

        return v;
    }
};
