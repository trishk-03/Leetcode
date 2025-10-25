class Solution {
public:
    int totalMoney(int n) {
        int week = n/7;
        int ans=0;
        int remaining = n%7;

        for(int i =0;i<week;i++){
            ans += 28+i*7;
        }
        for(int i =0;i<remaining;i++){
            ans+= (i+1+week);
        }
        return ans;
        
    }
};