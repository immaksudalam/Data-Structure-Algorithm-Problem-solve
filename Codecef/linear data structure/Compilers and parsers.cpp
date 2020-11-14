#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0;
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='<')st.push('<');
            else if(s[i]=='>' && st.size()!=0){
                st.pop();
                if(st.size()==0)
                cnt= i+1;
            }
            else break;
        }
       cout<<cnt<<endl;
    }
}
