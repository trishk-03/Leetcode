class Solution {
public:
    bool notzero(int k){
        while(k){
            int digit = k%10;
            if(digit == 0) return false;
            k= k/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a =0;
        int b=0;
        for(int i=1;i<n;i++){
            a=n-i;
            if(notzero(a) && notzero(i)) return{i,a};
        }
        return {-1,-1};
        
    }
};