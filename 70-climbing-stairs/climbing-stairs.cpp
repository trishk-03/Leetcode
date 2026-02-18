class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        
        int prev2=1;
        int prev =2;
        int curr;

        for(int i =3;i<=n;i++){
            curr = prev + prev2;
            prev2= prev;
            prev = curr;
        }
        return curr;
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1,-1);

        dp[1]=1;
        dp[2]=2;

        for(int i =3;i<=n;i++){
            dp[i]= dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};