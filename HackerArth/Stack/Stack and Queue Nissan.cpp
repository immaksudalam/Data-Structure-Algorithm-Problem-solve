#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k; cin>>n>>k;
    priority_queue<long long>a;
    long long ans=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        a.push(x);
    }
    for(int i=0; i<k; i++){
        ans+= a.top();
        a.pop();
    }
    cout<<ans<<endl;
}
