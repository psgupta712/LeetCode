class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int count = 0;
        int value = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] == nums[i+1]){
                count++;
                value = nums[i];
            }

        }
        if(count >= 1){
            return value;
        }
        return 0;
    }
};