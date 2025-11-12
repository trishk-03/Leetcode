class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int maxlen =0;
        int currlen =1;
        int distinct =1;

        for(int i=1;i<word.size();i++){
            if(word[i]>= word[i-1]){
                currlen++;
                if(word[i]>word[i-1]){
                    distinct++;
                }
            }
            else{
                currlen =1;
                distinct =1;
            }

            if(distinct == 5)
            maxlen = max(maxlen,currlen);
        }
        return maxlen;
    }
};