class Solution {
public:
    string convertToTitle(int cn) {
        string ans = "";
        while(cn > 0) {
            ans = (char)((--cn % 26) + 'A') + ans; // SOME MATHS HERE...
            cn /= 26;
        }
        return ans;
    }
};