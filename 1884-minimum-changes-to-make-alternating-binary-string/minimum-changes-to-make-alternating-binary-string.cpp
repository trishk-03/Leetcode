class Solution {
public:
    int minOperations(string s) {
        int startWithZero = 0;
        int startWithOne = 0;

        for(int i = 0; i < s.length(); i++) {

            // pattern 010101...
            if(i % 2 == 0 && s[i] != '0') startWithZero++;
            if(i % 2 == 1 && s[i] != '1') startWithZero++;

            // pattern 101010...
            if(i % 2 == 0 && s[i] != '1') startWithOne++;
            if(i % 2 == 1 && s[i] != '0') startWithOne++;
        }

        return min(startWithZero, startWithOne);
    }
};