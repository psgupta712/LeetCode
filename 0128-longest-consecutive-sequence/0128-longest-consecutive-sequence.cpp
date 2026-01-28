class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
        return 0;

        sort(nums.begin(), nums.end());
        int longestSequence = 1;
        int currEle = 1;


        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1] + 1){
                currEle++;
            }
            else {
                longestSequence = max(currEle, longestSequence);
                currEle = 1;
            }
        }
        return max(longestSequence, currEle);
    }
};