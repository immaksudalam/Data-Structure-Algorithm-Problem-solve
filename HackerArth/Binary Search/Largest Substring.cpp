#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    string s;
    cin>>s;
    int zero[n+1]={0};
    int one[n+1] = {0};
    int temp[n+1]={0};
    int mini[n+1]={0};
    s= " "+s;
    for(int i=1; i<=n; i++){
        zero[i] = zero[i-1];
        one[i] = one[i-1];
        if(s[i]=='0') zero[i]++;
        else one[i]++;
        temp[i] = zero[i] - one[i];
        mini[i] = min(mini[i-1], temp[i]);
    }
    int ans =0;
    for(int i=1; i<=n; i++){
        int l=0, r = i;
        while(l <= r){
            int mid = (l+r)/2;
            if(mini[mid] < temp[i]){
                ans = max(ans, i - mid);
                r = mid -1;
            }
            else l = mid+1;
        }
    }
    cout<<ans<<endl;
}
