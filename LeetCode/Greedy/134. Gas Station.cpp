class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int>v(n);
        int s=0;
        for(int i=0; i<n; i++){
            v[i] = gas[i]-cost[i];
            s+= v[i];
        }
        if(s<0) return -1;
        int ans = 0;
        int ps=0;
        for(int i=0; i<n; i++){
            ps+=v[i];
            if(ps <0){
                ans = i+1;
                ps=0;
            }
        }
        return ans;
    }
};
