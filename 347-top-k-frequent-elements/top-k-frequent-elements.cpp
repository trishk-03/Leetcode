class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> v;
        for (auto& it : freq) {
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> result;
        for (int i = 0; i < k && i < v.size(); i++) {
            result.push_back(v[i].first);
        }

        return result;
    }
};
