class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        
        int ans = INT_MAX;
        while(l<= r){
            int mid = (l + r)/2;
            bool flag = false;
            
            long long sum =0;
            int left =0;
            for(int i=0; i<mid; i++) sum += nums[i];
            for(int i= mid; i<n; i++){
                sum += nums[i];
                if(sum >= target){
                    flag = true;
                    break;
                }
                sum -= nums[left++];
            }
            if(flag){
                ans = mid + 1;
                r = mid -1;
            }
            else l = mid +1;
        }
        
        if(ans == INT_MAX) return 0;
        return ans;
    }
};
