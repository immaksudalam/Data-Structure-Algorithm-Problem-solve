class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>>res;
      sort(nums.begin(), nums.end());
      int n = nums.size();
        for(int i=n-1; i>=2; i--){
            if(i != n-1 && nums[i] == nums[i+1])continue;
            int right = i-1;
            int left = 0;
            while(left<right){
                if(nums[left] + nums[right] + nums[i] > 0) right--;
                else if(nums[left] + nums[right] + nums[i]<0) left++;
                else{
                    res.push_back({nums[left], nums[right], nums[i]});
                    while(left < right && nums[left] == nums[left+1])left++;
                    while(left< right && nums[right] == nums[right-1]) right--;
                    left++, right--;
                }
            }
        }
        return res;
    }
};
