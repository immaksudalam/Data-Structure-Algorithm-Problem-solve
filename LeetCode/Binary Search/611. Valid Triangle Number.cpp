class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=n-1; i>=2; i--){ 
            int right = i-1;
            int left = 0;
            while(left<right){
                if(nums[left]+nums[right]> nums[i]){
                    ans+= (right - left);
                    right--;
                }
                else left++;
            }
        }
        return ans;
    }
};
