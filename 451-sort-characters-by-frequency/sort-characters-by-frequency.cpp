class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char,int> map;
    for(char w: s){
        map[w]++;
    }
    vector<pair<char,int>> arr(map.begin(),map.end());
    sort(arr.begin(), arr.end() ,[](auto&a, auto&b){
        return a.second>b.second;
    });

    string answer;
    for(auto &s : arr){
        answer.append(s.second,s.first);
    }
    return answer;
    }
};