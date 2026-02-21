class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) 
    {
        unordered_map<int,int> num2freq, freqmap;
        for(auto n : nums)
        {
            freqmap[num2freq[n]]--;
            num2freq[n]++;
            freqmap[num2freq[n]]++;
        }

        for(int n : nums)
        {
            if(freqmap[num2freq[n]] == 1)
                return n;
        }
        return -1;
    }
};