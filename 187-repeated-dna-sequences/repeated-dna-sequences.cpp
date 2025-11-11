class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        vector<string>ans;
        if(s.length()<10) return ans;

        for(int i =0;i<s.size();i++){
            string sub = s.substr(i,10);
            m[sub]++;
        }

        for(auto &i :m){
            if(i.second >1 )
            ans.push_back(i.first);
        }

        return ans;

    }
};