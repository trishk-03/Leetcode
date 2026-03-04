class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int sign = 1;
        long result = 0;

        // skip spaces
        while(i < s.size() && s[i] == ' ')
            i++;

        // sign
        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        // digits
        while(i < s.size() && isdigit(s[i])){
            int digit = s[i] - '0';

            result = result * 10 + digit;

            // overflow check
            if(sign * result > INT_MAX) return INT_MAX;
            if(sign * result < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * result;
    }
};