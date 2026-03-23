class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> maxProd(m, vector<long long>(n));
        vector<vector<long long>> minProd(m, vector<long long>(n));

        maxProd[0][0] = minProd[0][0] = grid[0][0];

        // first column
        for(int i = 1; i < m; i++){
            maxProd[i][0] = minProd[i][0] = maxProd[i-1][0] * grid[i][0];
        }

        // first row
        for(int j = 1; j < n; j++){
            maxProd[0][j] = minProd[0][j] = maxProd[0][j-1] * grid[0][j];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                long long a = maxProd[i-1][j] * grid[i][j];
                long long b = minProd[i-1][j] * grid[i][j];
                long long c = maxProd[i][j-1] * grid[i][j];
                long long d = minProd[i][j-1] * grid[i][j];

                maxProd[i][j] = max({a,b,c,d});
                minProd[i][j] = min({a,b,c,d});
            }
        }

        long long ans = maxProd[m-1][n-1];

        if(ans < 0) return -1;

        return ans % 1000000007;
    }
};