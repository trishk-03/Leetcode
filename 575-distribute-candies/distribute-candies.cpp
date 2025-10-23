class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size()/2;

        set<int> s;
        for(int i= 0;i<candyType.size();i++){
            if(s.find(candyType[i])==s.end()){
                s.insert(candyType[i]);
            }
        }

        if(n>=s.size()) return s.size();
        else return n;
    }
};