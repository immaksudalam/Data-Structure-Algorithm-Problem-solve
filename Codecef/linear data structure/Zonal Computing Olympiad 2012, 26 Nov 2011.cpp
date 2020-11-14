#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    stack<int>st;
    int mpos, m=0;
    int lpos, l=0;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        cnt++;
        if(ar[i]==1)st.push(1);
        else{
            int t = st.size();
            if(t>m){
              m=t;
              mpos=i;
            }
            st.pop();
        }
        if(st.size()==0){
            if(cnt>l){
                lpos=i-cnt+2;
                l=cnt;
            }
            cnt=0;
        }
    }
    cout<<m<<" "<<mpos<<" "<<l<<" "<<lpos<<endl;

}
