class Solution {
public:
    set<vector<int>>st;
    vector<vector<int>>ans;
    
    void permute(vector<int>&nums, int pos){
        if(pos ==nums.size()){
            if(st.find(nums) == st.end()){
                st.insert(nums);
                ans.push_back(nums);
            }
            return;
        }
        
        for(int i= pos; i<nums.size(); i++){
            swap(nums[pos], nums[i]);
            permute(nums, pos+1);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(nums, 0);
        
        return ans;
    }
};
