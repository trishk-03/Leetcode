class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
         return s;
        vector<string> rows(numRows);
        int currRow = 1;
        bool goingDown = true;

        for (char c : s) {
            rows[currRow-1] += c;

            if (currRow == 1)
                goingDown = true;
            else if (currRow == numRows)
                goingDown = false;

            currRow += goingDown ? 1 : -1;
        }

        string ans;

        for (string row : rows)
            ans += row;

        return ans;
    }
};