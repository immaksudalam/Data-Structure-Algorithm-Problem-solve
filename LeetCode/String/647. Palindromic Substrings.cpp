class Solution {
public:
    int generate(string &s, int l, int r){
        int res = 0;
        while(l >=0 && r<s.size() && s[l] == s[r]){
            res++;
            l--, r++;
        }
        return res;
    }
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++){
            //odd length
            res += generate(s, i, i);
            //even length
            res += generate(s, i, i+1);
        }
        return res;
    }
};
