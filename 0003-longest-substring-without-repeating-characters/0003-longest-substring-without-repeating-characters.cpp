class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int right = 0;
        int longest = 0;

        while(right < s.size()) {
            if(st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                longest = max(longest, (int)st.size());
                right++;
            }
            else {
                st.erase(s[left]);
                left++;
            }
        }

        return longest;
    }
};
