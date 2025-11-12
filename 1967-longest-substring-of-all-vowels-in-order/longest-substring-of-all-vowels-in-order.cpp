class Solution {

/*
in this first find check if the another word is greater or equal to the word if it is then 
increment the current length 
else if it is not then move ahead 

then check if it is equal or greater 
if it is equal then increment the length 
otherwise if is greater than then it means it is a distinct vowel 

if any time they are not then reset the value of curr and distinct to 1 again 
but if the distinct becomes equal to the 5 which means then the all distinct vowels are there 

then track the length of window by comparing maxlen and currlen

return the answer
*/
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