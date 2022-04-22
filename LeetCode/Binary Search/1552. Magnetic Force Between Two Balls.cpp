class Solution {
public:
    bool isPossible(int mid, vector<int>&position, int m){
        int cnt = m;
        cnt--;
        long long last = position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i]-last>= mid){
                cnt--; 
                last = position[i];
            }
        }
        if(cnt<=0) return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        sort(position.begin(), position.end());
        int l=0, r = 1e9;
        while(l<= r){
            int mid = (l + r)>>1;
            if(isPossible(mid, position, m)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};
