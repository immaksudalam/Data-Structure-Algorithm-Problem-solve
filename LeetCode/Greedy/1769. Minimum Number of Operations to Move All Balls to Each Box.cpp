class Solution {
public:
    vector<int> minOperations(string boxes) {
        int cnt = 0;
        int n = boxes.size();
        vector<int>left(n, 0);
        for(int i=0; i<n; i++) {
            if(i==0){
                if(boxes[i]=='1')cnt++;
                continue;
            }
            left[i] = left[i-1] + cnt;
            if(boxes[i]=='1')cnt++;
        }
        vector<int>right(n, 0);
        cnt=0;
        for(int i = n-1; i>=0; i--){
            if(i==n-1){
                if(boxes[i]=='1')cnt++;
                continue;
            }
            right[i] = right[i+1]+cnt;
            if(boxes[i]=='1')cnt++;
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++)ans[i] = left[i] + right[i];
        return ans;
    }
};
