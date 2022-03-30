class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = INT_MIN;
        int l =0, r = height.size()-1;
        while(l< r){
            int len = r - l;
            res = max(res, len*(min(height[l], height[r])));
            
            if(height[l]<height[r]) l++;
            else r--;
        }
        return res;
    }
};
