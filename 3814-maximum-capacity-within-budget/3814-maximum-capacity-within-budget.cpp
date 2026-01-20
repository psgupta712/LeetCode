class Solution {
public:
    int maxCapacity(vector<int>& cost, vector<int>& cap, int bud) {
        int n = cost.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {cost[i], cap[i]};
        }
        sort(a.begin(), a.end());
        vector<int> pre(n);
        pre[0] = a[0].second;
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], a[i].second);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curr = a[i].first;
            int rem = bud - curr - 1;
            pair<int, int> temp = {rem, INT_MAX};
            auto it = upper_bound(a.begin(), a.begin()+i, temp);
            int idx = it - a.begin() ;
            if (idx > 0) {
                ans = max(ans, a[i].second + pre[idx-1]);
            }

            if(curr<bud){
            ans = max(ans, a[i].second);
            }
        }
        return ans;
    }
};