class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //firstly we have to find that point at which we can increase lexicographical order.
        int idx = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        //if breaking point does not found then reverse the array
        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }


        // find the next greater element of nums[idx], then swap
        for(int i=n-1; i>idx; i--){
            if(nums[i] > nums[idx]){
                swap(nums[idx], nums[i]);
                break;
            }
        }


        // After swapping sort the array from the idx+1 , nums.end()
        reverse(nums.begin() + idx + 1, nums.end());
        return ;
    }
};