class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int maxlen = 1;
        int n = s.size();
        int start=0, end =0;
        
        //odd length
        for(int i=0; i<n-1; i++){
            int l = i, r = i;
            while(l>=0 && r<n){
                if(s[l] == s[r]) l--, r++;
                else break;
            }
            int len = r - l -1;
            if(len > maxlen){
                maxlen = len;
                start = l+1;
                end = r-1;
            }
        }
        
        //odd length
        for(int i=0; i<n-1; i++){
            int l = i, r = i+1;
            while(l>=0 && r<n){
                if(s[l] == s[r]) l--, r++;
                else break;
            }
            int len = r - l -1;
            if(len > maxlen){
                maxlen = len;
                start = l+1;
                end = r-1;
            }
        }
        
        return s.substr(start, maxlen);
    }
};
