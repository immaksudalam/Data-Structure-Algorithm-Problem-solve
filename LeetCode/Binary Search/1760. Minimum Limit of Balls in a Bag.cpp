class Solution {
public:
    bool isPossible(int mid, vector<int>&nums, int operation){
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%mid == 0){
                cnt += (nums[i]/mid) - 1;
            }
            else{
                cnt += (nums[i]/mid);
            }
        }
        return cnt<=operation;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
       int n = nums.size();
       int l = 1, r = 1e9;
       int ans = 1;
       while(l <= r){
           int mid = (l + r)>>1;
           if(isPossible(mid, nums, maxOperations)){
               ans = mid;
               r = mid-1;
           }
           else l = mid + 1;
       }
      return ans;
    }
};
