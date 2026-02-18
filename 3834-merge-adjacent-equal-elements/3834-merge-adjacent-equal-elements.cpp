class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans;
        for(auto x: nums){
            if(!ans.empty() && ans.back()==x){
                long long sum = ans.back()+x;
                ans.pop_back();
                while(!ans.empty() && ans.back()==sum){
                    sum=ans.back()+sum;
                    ans.pop_back();
                }
                ans.push_back(sum);
            }else{
                ans.push_back(x);
            }
        }
        return ans;
    }
};