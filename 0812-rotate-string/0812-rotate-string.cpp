class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.size();

        int count = 0;
        while(s!=goal && count <= len-1){
            char last = s[len-1];
            for(int i=len-2; i>=0; i--){
                s[i+1]=s[i];
            }
            s[0]=last;
            count++;
        }
        return s==goal;
    }
    
};