#include <bits/stdc++.h>
using namespace std;
#define mod1 1000000007
#define mod2 2038074743
#define p1 31
#define p2 37
#define pb push_back

#define ll long long
string a, b;
ll n, m;
ll pow1[50010], invpow1[50010];
ll pow2[50010], invpow2[50010];
ll hash1[50010], hash2[50010], hash3[50010], hash4[50010];
void compute_hash()
{
    hash1[0] = hash2[0] = hash3[0]= hash4[0]=0;
    for(ll i=1; i<=n; i++){
        hash1[i] = (hash1[i-1] + (a[i-1]-'a' +1)* pow1[i-1])%mod1;
        hash2[i]= (hash2[i-1] + (a[i-1]-'a' +1)* pow2[i-1])%mod2;
    }
    for(ll i=1; i<=m; i++){
      hash3[i]= (hash3[i-1] + (b[i-1]-'a' +1)* pow1[i-1])%mod1;
      hash4[i]= (hash4[i-1] + (b[i-1]-'a' +1)* pow2[i-1])%mod2;
    }
}
bool check(ll x)
{
    map<ll, ll> mp1, mp2;
    for(ll i=1; i<=m-x+1; i++){
        ll val=(hash3[i+x-1] - hash3[i-1] + mod1)%mod1;
        val = (val* invpow1[i-1])%mod1;
        mp1[val]++;
        val = (hash4[i+x-1] - hash4[i-1] + mod2)%mod2;
        val = (val*invpow2[i-1])%mod2;
        mp2[val]++;
    }
    for(ll i=1; i<=n-x+1; i++){
        ll val1= (hash1[i+x-1] - hash1[i-1] +mod1)%mod1;
        val1 = (val1*invpow1[i-1])%mod1;
        ll val2 = (hash2[i+x-1]- hash2[i-1]+mod2)%mod2;
        val2 = (val2*invpow2[i-1])%mod2;
        if(mp1[val1] && mp2[val2])
            return true;
    }
    return false;
}

ll binSearch(ll low, ll high)
{
    ll res=0;
    while(low <= high){
        ll mid = (low+high)/2;
        if(check(mid)){
            res = mid;
            low = mid+1;
        }
        else high= mid-1;
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    pow1[0]= pow2[0]=1;
    for(ll i= 1; i<5*1e4; i++){
        pow1[i]= (pow1[i-1]*p1)%mod1;
        pow2[i]= (pow2[i-1]*p2)%mod2;
    }
    //modular arithmetric
    invpow1[0]=invpow2[0]=1;
    invpow1[1]=129032259;
    invpow2[1]=330498607;
    for(ll i=2;i<=5*1e4;i++)
    {
        invpow1[i]=(invpow1[i-1]*129032259)%mod1;
        invpow2[i]=(invpow2[i-1]*330498607)%mod2;
    }
    while(t--){
        cin>> n>>m;
        cin>>a>>b;
        compute_hash();
        ll k = binSearch(1, n);
        cout<<k<<endl;
        if(!k)continue;
        set<pair<string, ll> >ans;
        map<ll, ll> mp1, mp2;
        for(ll i=1; i<= m-k+1; i++){
            ll val=(hash3[i+k-1]- hash3[i-1]+mod1)%mod1;
            val = (val*invpow1[i-1])%mod1;
            mp1[val]++;
            val = (hash4[i+k-1]-hash4[i-1]+mod2)%mod2;
            val=(val*invpow2[i-1])%mod2;
            mp2[val]++;
        }
        for(ll i=1;i<=n-k+1;i++)
        {
            ll val1=(hash1[i+k-1]-hash1[i-1]+mod1)%mod1;
            val1=(val1*invpow1[i-1])%mod1;
            ll val2=(hash2[i+k-1]-hash2[i-1]+mod2)%mod2;
            val2=(val2*invpow2[i-1])%mod2;
            if(mp1[val1] && mp2[val2])
                ans.insert({a.substr(i-1,k),mp1[val1]});
        }
        for(auto it:ans){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}
