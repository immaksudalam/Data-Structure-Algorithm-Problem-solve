class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size()-1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int missing = arr[mid] - (mid +1);
            
            if(missing >= k) r = mid -1;
            else l = mid +1;
        }
        if(r == -1) return k;
        
        return arr[r] + k - (arr[r] - (r +1));
    }
};
