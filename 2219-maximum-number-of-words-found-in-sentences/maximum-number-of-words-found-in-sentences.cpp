class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxcount =0;
        int count =0;
        for(int i =0;i<sentences.size();i++){
            int count =1;
            int j =0;
            while( j<sentences[i].size()){
                if(sentences[i][j]== ' ')
                count ++;
                j++;
            }
        maxcount = max(maxcount,count);
        }
        return maxcount;

    }
};