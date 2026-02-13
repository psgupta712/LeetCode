class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>res;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            auto it=find(res.begin(),res.end(),s[i]);
            if(it!=res.end()){
                res.erase(res.begin(),it+1);
                res.push_back(s[i]);
            }
            else{
                res.push_back(s[i]);
            }
            maxi=max(maxi,(int)res.size());
        }
        return maxi;
    }
};