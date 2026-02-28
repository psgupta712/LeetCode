class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
       int n = nums.size();
        int closestDiff = INT_MAX;
        int closestSum = 0;
        
        for(int i=0; i<n-2; i++){
            int left = i+1;
            int right = n-1;
        while(left < right ){
            int currSum = nums[i] + nums[left] + nums[right];
            int difference = abs(currSum - target);
            if(difference < closestDiff) {
                closestDiff = difference;
                closestSum = currSum;
            }
            if(currSum == target) return currSum;
            if(currSum < target ) {
                left++;
            } else {
                right--;
            }
        }
        }
        return closestSum;
    }
};