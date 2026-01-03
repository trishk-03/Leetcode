class Solution {
private:
    bool search(int &target , vector<int>& row){
        int low = 0;
        int high = row.size()-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(target == row[mid])
            return true;

            else if(target<row[mid])
            high = mid-1;

            else
            low = mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        while(start<m){
          if( target >= matrix[start][0] && target <= matrix[start][n-1])
          return search(target,matrix[start]);
          else
          start++;  
        }
        return false;
    }
};