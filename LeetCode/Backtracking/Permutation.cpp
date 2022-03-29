class Solution {
public:
    vector<vector<int>> permutation(vector<int> nums){
        
        if(nums.size()==0) return {{}};
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            vector<int> nums2;
            for(int j=0; j<nums.size(); j++){
                if(i==j)continue;
                nums2.push_back(nums[j]);
            }
            vector<vector<int>> v = permutation(nums2);
            
            for(int k=0; k<v.size(); k++){
                v[k].push_back(nums[i]);
                ans.push_back(v[k]);
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        return permutation(nums);
    }
};
