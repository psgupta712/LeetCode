class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;

        int low = 0, mid = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid++], nums[low++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
