class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0, right = col - 1;
        int top = 0, bottom = row - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {

            // Traverse top row (left → right)
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse right column (top → bottom)
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse bottom row (right → left)
            if (top <= bottom) { // check to avoid duplicate rows
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse left column (bottom → top)
            if (left <= right) { // check to avoid duplicate columns
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
