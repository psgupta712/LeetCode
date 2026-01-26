class Solution {
public:
    string reverseWords(string s) {
        int end = s.size() - 1;
        int startVal = 0;
        int endVal = end;

        string ans = "";

        for(int i=end; i>=0; i--) {
            if(s[i] == ' ') {
                startVal = i + 1;

                for(int j=startVal; j<=endVal; j++) {
                    ans += s[j];
                }

                ans += ' ';
                endVal=i - 1;
            }
        }

        for(int j=0; j<=endVal; j++) {
            ans += s[j];
        }

        string clean = "";
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] != ' ') {
                clean += ans[i];
            } 
            else {
                if(clean.size() == 0 || clean.back() != ' ') {
                    clean += ' ';
                }
            }
        }

        if (clean.size() > 0 && clean[0] == ' ')
            clean.erase(0,1);

        if (clean.size() > 0 && clean.back() == ' ')
            clean.pop_back();
        return clean;
    }
};
