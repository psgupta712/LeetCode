class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicate = -1;
        int missing = -1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                duplicate = nums[i];
            }
        }

        if(nums[0] != 1){
            missing = 1;
        }
        else{
            for(int i=1; i<nums.size(); i++){
                if(nums[i] == nums[i-1]) continue;
                if(nums[i] != nums[i-1] + 1){
                    missing = nums[i-1] + 1;
                    break;
                }
            }
        }

        //if missing is not found
        if(missing == -1){
            missing = nums.size();
        }

        return {duplicate, missing};
    }
};