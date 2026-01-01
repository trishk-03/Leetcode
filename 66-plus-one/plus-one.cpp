class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size() - 1;

        while (l >= 0) {
            if (digits[l] < 9) {
                digits[l]++;
                return digits;   
            }
            digits[l] = 0;       
            l--;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
