#define ll long long
#define mod 1000000007
#include<bits/stdc++.h>
using namespace std;
ll hashes[100005],pows[100005];
int p = 31;
int compute_hash(int l,int r)
{
    return  ((hashes[r+1]-(hashes[l]*pows[r-l+1])%mod)+mod)%mod;


}
int main()
{
    pows[0]=1;
    for(int i=1;i<100005;i++)
    {
        pows[i]=(pows[i-1]*p)%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        hashes[0]=0;
        for(int i=1; i<=n; i++){
            hashes[i]=(hashes[i-1]+ (s[i-1]-'a'+1)*pows[i-1])%mod;
        }
        int cnt=0;
        for(int i=2;i<=n-2;i+=2)
        {
            int l1=0,r1=i/2-1;//T1
            int l2=r1+1,r2=i-1;//T2
            int l3=i,r3=(i+n)/2-1;//T3
            int l4=r3+1,r4=n-1;//T4
            if(compute_hash(l1,r1)==compute_hash(l2,r2)&&compute_hash(l3,r3)==compute_hash(l4,r4))
            {
                cnt++;
            }




        }
        cout<<cnt<<endl;




    }



}
