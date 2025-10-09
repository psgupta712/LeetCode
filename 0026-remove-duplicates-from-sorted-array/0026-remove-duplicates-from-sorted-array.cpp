class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int i=0; i<nums.size(); i++){
            count++;
        }
        return count;
    }
};