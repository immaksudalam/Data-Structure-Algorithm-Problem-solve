class Solution {
public:
    unordered_map<int, int>count;
    int m = 0;
    void permute(vector<int>&nums, int pos, int sum){
        if(pos == nums.size()){
            m = max(m, sum);
            count[sum]++;
            return;
        }
        //do not consider ith element
        permute(nums, pos+1, sum);
        
        //consider ith element
        sum |= nums[pos];
        permute(nums, pos+1, sum);
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        count.clear();
        m =0;
        
        permute(nums, 0, 0);
        
        return count[m];
    }
};
