class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel = 0;
        int conso = 0;

        char vwl[] = "aeiou";
        for(int i=0; i<s.size(); i++){
            if(isalpha(s[i])){
                if(strchr(vwl, s[i])){
                    vowel++;
                }
                else{
                    conso++;
                }
            }
        }


        if(conso == 0){
            return 0;
        }
        else{
            return floor(vowel/conso);
        }
    }
};