/* Let f(x) = x^3 + x^2 + x
There are t test cases. In each test cases you are given a positive integer ‘m’ and you have to find maximum possible value of integer ‘x’ such that f(x) <= m
1 <= t <= 10^5
1 <= m <= 10^18
*/






#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll x){
    return x*x*x + x*x + x;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll m; cin>>m;
        ll l=0, r = 1000000;
        ll ans = -1;
        while(l <= r){
            ll mid = (l + r)/2;
            if(f(mid) <= m){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid -1;
            }
        }
        cout<<ans<<endl;
    }
}
