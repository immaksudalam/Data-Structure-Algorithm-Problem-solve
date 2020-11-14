#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       int arr[n];
       for(int i=0; i<n; i++){
          cin>>arr[i];
       }
       int ans =0;
       map<int, int>mp;
       queue<int>q;
       for(int i=0; i<n; i++){
          mp[arr[i]]++;
          if(mp.size()< k) q.push(arr[i]);
          else{
            int t=q.size();
            ans = max(ans,t);
            mp[q.front()]--;
            if(mp[q.front()]==0)mp.erase(q.front());
            q.pop();
            q.push(arr[i]);
          }
       }
       int t = q.size();
       ans = max(ans, t);
       cout<<ans<<endl;
    }
}
