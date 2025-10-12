class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> res;

        for (int i = k;; i++) {
            if (k % 2)
                res.push_back((double)*mid);
            else
                res.push_back(((double)*mid + *prev(mid)) / 2.0);

            if (i == nums.size())
                break;

            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;
            if (nums[i - k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }

        return res;
    }
};