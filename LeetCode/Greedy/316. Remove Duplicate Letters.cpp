class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int>lastIndex(128);
        bool seen[128];
        stack<char>st;
        for(int i=0; i<n; i++)
            lastIndex[s[i]]=i;
        for(char c = 'a'; c<='z'; c++) seen[c]=false;
        for(int i=0; i<n; i++){
            if(seen[s[i]]) continue;
            while(!st.empty() && s[i] < st.top() && i < lastIndex[st.top()]){
                seen[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]]=true;
        }
        string ans="";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
