class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                int idx = val - 1;
                if (nums[idx] > 0) {
                    nums[idx] = -nums[idx];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
