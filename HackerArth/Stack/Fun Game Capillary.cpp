#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n; cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll ar[n];
    for(int i=n-1, j=0; i>=0; i--, j++){
        ar[j]=arr[i];
    }
    stack<ll> a,b;
    for(int i=0; i<n; i++){
       a.push(arr[i]);
       b.push(ar[i]);
    }
    vector<ll>v;
    while(!a.empty() && !b.empty()){
        if(a.top() > b.top()){
            v.push_back(2);
            b.pop();
        }
        else if(a.top() < b.top()){
            v.push_back(1);
            a.pop();
        }
        else{
            v.push_back(0);
            a.pop();
            b.pop();
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}
