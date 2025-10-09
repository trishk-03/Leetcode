class Solution {
public:
    int reverse(int x) {
        long long a = llabs((long long)x); 
        int rev = 0;

        while (a > 0) {
            int digit = a % 10;

            // Check for overflow
            if (rev > (INT_MAX - digit) / 10) {
                return 0; 
            }

            rev = rev * 10 + digit;
            a /= 10;
        }

        return x < 0 ? -rev : rev;
    }
};
