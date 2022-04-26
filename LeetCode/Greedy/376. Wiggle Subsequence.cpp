class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return n;
        int ans = 1;
        int ok = 0;
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i-1]>0 && ok != 1){
                ans++;
                ok = 1;
            }
            else if(nums[i] - nums[i-1]<0 && ok!= -1){
                ans++;
                ok = -1;
            }
        }
        return ans;
    }
};
