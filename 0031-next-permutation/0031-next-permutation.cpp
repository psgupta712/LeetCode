class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //STEP 1 = find the pivot
        int pivot = -1;
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
 
            if(pivot==-1){     //It means the array is sorted in ascending order from right side.
                reverse(nums.begin(), nums.end());
                return ;
            }

        //STEP 2 = find the just greater element than pivot
        for(int i=nums.size()-1; i>pivot; i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        //STEP 3 = sort the array after the pivot element in increasing order from right side.
        int i=pivot+1; 
        int j=nums.size()-1;
        while(i<j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};