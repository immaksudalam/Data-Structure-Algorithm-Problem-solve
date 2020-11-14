#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    long long n,k;
    cin>>n>>k;
    stack<pair<long long, long long>>st;
    long long x;
    long long ans =1;
    for(int i=0; i<n; i++){
         cin>>x;
         if(st.empty() || st.top().first <= x) st.push(make_pair(x, i));
         else{
            while(!st.empty() && x< st.top().first){
                ans*=(i- st.top().second+1);
                ans%=mod;
                st.pop();
              }
              st.push(make_pair(x, i));
          }
     }
     cout<<ans<<endl;
}
