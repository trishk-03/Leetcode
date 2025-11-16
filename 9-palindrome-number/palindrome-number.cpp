class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        long long digit =0;
        int n = x;
        while(n>0){
            int num = n%10;
            digit = digit*10 + num;
            n = n/10;
        }

        if(digit == x) return true;
        return false;
    }
};