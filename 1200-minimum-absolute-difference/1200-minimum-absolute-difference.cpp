class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans; 
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mn = INT_MAX; 
        
        for (int i = 0; i < n - 1; i++) {
            int a = arr[i];
            int b = arr[i + 1];
            
            if (b - a < mn) {
                ans.clear();
                mn = b - a;
                ans.push_back({a, b});
            } 
            else if (b - a == mn) {
                ans.push_back({a, b});
            }
        }
        
        return ans;
    }
};