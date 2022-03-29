class Solution {
public:
    vector<int>ansset;
    void helper(vector<int>&nums, int pos, int xr){
        ansset.push_back(xr);
        for(int i=pos; i<nums.size(); i++){
            xr = xr^nums[i];
            helper(nums, i+1, xr);
            xr = xr^nums[i];
        }
    }
    int subsetXORSum(vector<int>& nums) {
        helper(nums, 0, 0);  
        int ans=0;
        for(int i=0; i<ansset.size(); i++) ans+= ansset[i];
        
        return ans;
    }
    
};
