class Solution {
public:
    void helper(vector<int>&v, int i, int k){
        if(v.size() == 1) return;
        
        i = (i+k-1)%v.size();
        v.erase(v.begin()+i);
        
        helper(v, i, k);
    }
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i=0; i<n; i++) v[i] = i+1;
        
        helper(v, 0, k);
        return v[0];
    }
};
