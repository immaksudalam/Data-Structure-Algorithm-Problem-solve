class Solution {
public:
    bool isPossible(vector<int>&bloomDay, int mid, int m, int k){
        int cnt = 0;
        int flower=0;
        int prev=-1;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid && (prev+1 == i || prev==-1)){
                flower++;
                if(flower == k){
                    cnt++;
                    flower = 0;
                    prev=-1;
                }
                else{
                    prev = i;
                }
            }
            else{
                prev  = -1;
                flower = 0;
            }
        }
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        int l = 1, r = 1e9;
        while(l <= r){
            int mid = (l + r)>>1;
            if(isPossible(bloomDay, mid,  m, k)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
