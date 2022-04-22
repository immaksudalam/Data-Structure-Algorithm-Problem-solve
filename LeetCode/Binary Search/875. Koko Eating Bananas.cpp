class Solution {
public:
    bool isPossible(int mid, vector<int>&piles, int &h){
        int cnt = 0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]<=mid)cnt++;
            else if(piles[i]%mid == 0) cnt+= (piles[i]/mid);
            else cnt += (piles[i]/mid)+1;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans;
        int l = 1, r = 1e9;
        while(l <= r){
            int mid = (l + r)>>1;
            if(isPossible(mid, piles, h)){
                ans = mid;
                r = mid -1;
            }
            else l = mid +1;
        }
        return ans;
    }
};
