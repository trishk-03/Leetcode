class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    int total=1;

    set<char> s;
    for(int i =0;i<text.size();i++){
        if(text[i] ==' '){
            total++;
        }     
    }
    for(int i =0; i<brokenLetters.size();i++){
        s.insert(brokenLetters[i]);
    }
    for(int i =0;i<text.size();i++){
        if(s.find(text[i]) != s.end()){
            total--;
            while(text[i]!= ' '&& i<text.size()){
                i++;
            }
        }
        
    }
    return total;
    }
};