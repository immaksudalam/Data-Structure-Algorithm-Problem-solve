class Solution {
public:
    bool isPossible(vector<int>&dist, int mid, double hour){
        double cnt = 0;
        for(int i=0; i<dist.size(); i++){
            if(i==dist.size()-1){
               cnt+= ((double)dist[i]/(double)mid); 
            }
            else if(dist[i]%mid==0) cnt+=(dist[i]/mid);
            else cnt+= (dist[i]/mid)+1;
        }
        return cnt<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = -1;
        int l = 1, r = 1e9;
        while(l <= r){
            int mid = (l + r)>>1;
            if(isPossible(dist, mid, hour)){
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
