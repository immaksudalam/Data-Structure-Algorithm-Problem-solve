// Time complexity = O(N*log(X*10^d))


#include <bits/stdc++.h>
using namespace std;

double multiply(double x, int n)
{
    double res = 1;
    for(int i=0; i<n; i++){
        res*=x;
    }
    return res;
}

int main()
{
    double exp = 1e-6;
    double x; cin>>x;
    int n; cin>>n;
    double l = 1, r = x, mid;
    while(r - l > exp){
        mid = (r + l)/2;
        if(multiply(mid, n) < x){
            l = mid;
        }
        else r = mid;
    }
    cout<<l<<endl;
}
