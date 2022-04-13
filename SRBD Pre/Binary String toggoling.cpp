#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    int arr[n][m];
    for(int i=0; i<n; i++)
       for(int j=0; j<m; j++)
          cin>>arr[i][j];
    map<string, int>mp;
    for(int i=0; i<n; i++){
        string s="";
        for(int j=0; j<m; j++){
            s+= arr[i][j] +'0';
        }
        mp[s]++;
    }
    int ans = 0;
    for(auto it= mp.begin(); it!=mp.end(); it++){
        int cnt = 0;
        string s = (*it).first;
        
        for(int j=0; j<s.size(); j++){
            if(s[j] == '0')cnt++;
        }
        int res = k-cnt;
        if(res >= 0 && (res == 0 || res %2 == 0)){
            ans = max(ans, (*it).second);
        }
    }
    cout<<ans<<endl;
}
