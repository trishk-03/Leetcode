class Solution {
private:
    void solve(string &tiles, vector<bool> &used, set<string> &s, string &v){
        
        if(v.length() > 0)
            s.insert(v);

        for(int i = 0; i < tiles.length(); i++){

            if(used[i]) continue;

            used[i] = true;
            v.push_back(tiles[i]);

            solve(tiles, used, s, v);

            v.pop_back();
            used[i] = false;
        }
    }

public:
    int numTilePossibilities(string tiles) {

        set<string> s;
        vector<bool> used(tiles.length(), false);
        string v = "";

        solve(tiles, used, s, v);

        return s.size();
    }
};