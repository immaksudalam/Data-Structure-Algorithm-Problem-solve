class Solution {
public:
    int solve(vector<int>& weights, int days,int mid)
    {
        int cnt=1;
        int temp=0;
        for(int i=0;i<weights.size();i++){
            if(temp+weights[i]<=mid) 
                temp+=weights[i];
            else{
                temp=weights[i];
                cnt++;
            }
        }
        return cnt<=days;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=INT_MAX;
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(solve(weights,days,mid))
            {
                ans=mid;
                h=mid-1;    
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
