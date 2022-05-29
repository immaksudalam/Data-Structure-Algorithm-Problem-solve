class Solution {
public:
    string operate(string s){
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string helper(int n){
        if(n==1) return "0";
        string prev = helper(n-1);
        string next = operate(prev);
        return prev + "1" + next;
    }
    char findKthBit(int n, int k) {
        string ans = helper(n);
        
        return ans[k-1];
    }
};
