class Solution {
    using ll = long long;
public:
    vector<long long> mergeAdjacent(vector<int>&nums) {
        int n = nums.size();
        stack<ll>st;
        for(int i = 0;i<n;i++){
            ll v = nums[i];
            while(!st.empty() && st.top() == v){
                v = st.top()*2*1LL;
                st.pop();
            }
            st.push(v);
        }
        vector<ll>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};