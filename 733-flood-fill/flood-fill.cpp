class Solution {
private:
    void solve(vector<vector<int>>& image, int& originalColor, int& color,
        int rows, int cols, int i, int j) {

        if (i < 0 || i >= rows || j < 0 || j >= cols) return;

        if (image[i][j] != originalColor) return;

        image[i][j] = color;
        solve(image, originalColor, color, rows, cols, i + 1, j);
        solve(image, originalColor, color, rows, cols, i, j + 1);
        solve(image, originalColor, color, rows, cols, i - 1, j);
        solve(image, originalColor, color, rows, cols, i, j - 1);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
        int color) {

        int rows = image.size();
        int cols = image[0].size();

        int originalColor = image[sr][sc];

        if (originalColor == color)
            return image;

        solve(image, originalColor, color, rows, cols, sr, sc);

        return image;
    }
};