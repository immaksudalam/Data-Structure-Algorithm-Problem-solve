#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s; cin>>s;
        int a=0, b=0;
        int opp1=n;
        int opp2=n;
        bool ans = false;
        for(int i=0; i<s.size(); i++){
            if(i%2==0)
            {
                if(s[i]=='1')a++, opp1--;
                else opp1--;
                if(a> b+opp2){
                        cout<<i+1<<endl;
                        ans= true;
                        break;
                }
                if(b> a+opp1){
                        cout<<i+1<<endl;
                        ans= true;
                        break;
                 }
            }
            else{
                if(s[i]=='1')b++, opp2--;
                else opp2--;
                if(b> a+opp1){
                        cout<<i+1<<endl;
                        ans=true;
                        break;
                 }
                 if(a> b+opp2){
                        cout<<i+1<<endl;
                        ans= true;
                        break;
                }
            }
        }
        if(!ans)cout<<n*2<<endl;
    }
}
