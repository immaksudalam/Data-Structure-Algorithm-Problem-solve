class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low =0, high = nums.size()-1;
        int mid;
        int ans;
        if(nums.size()==1)return 0;
        while(low < high){
            int mid = (low + high)/2;
            
            if(nums[mid] < nums[mid+1]){
                low = mid+1;
                ans = mid+1;
            }
            else{
                high = mid;
                ans = mid;
            }
        }
        
        return ans;
    }
};
