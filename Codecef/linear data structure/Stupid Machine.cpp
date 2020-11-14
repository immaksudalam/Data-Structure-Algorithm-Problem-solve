#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    long long ans=0;
    long long cmin=0;
    for(int i=0; i<n; i++){
        long long a;
        cin>>a;
        if(i==0){
            ans+=a;
            cmin=a;
            continue;
        }
        if(a>=cmin){
            ans+=cmin;
        }
        else{
           ans+=a;
           cmin=a;
        }
    }
    cout<<ans<<endl;
  }
}
