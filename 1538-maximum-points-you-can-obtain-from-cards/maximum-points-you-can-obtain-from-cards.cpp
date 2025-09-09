class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l =0;
        int r =0;
        int maxsum =0;

        for(int i =0;i<k;i++){
            l = l + cardPoints[i];
            maxsum = l;
        }
         int right_idx =cardPoints.size()-1;
        for(int i = k-1 ;i>=0; i--){
            l = l - cardPoints[i];
            r = r + cardPoints[right_idx];
            right_idx --;
            maxsum = max(maxsum , l+r);
        } 
        return maxsum;
        
    }
};