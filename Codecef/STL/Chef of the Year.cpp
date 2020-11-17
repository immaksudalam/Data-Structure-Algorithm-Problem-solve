#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int>a, pair<string, int>b)
{
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}
int main()
{
    int n, m;
    cin>>n>>m;
    map<string, string>country;
    map<string, int>email;
    for(int i=0; i<n; i++){
        string a,b;
        cin>>a>>b;
        country[a]=b;
    }
    for(int i=0; i<m; i++){
        string a;
        cin>>a;
        email[a]++;
    }
    vector<pair<string, int> >v;
    for(auto it=email.begin(); it!=email.end(); it++){
        v.push_back(make_pair((*it).first, (*it).second));
    }
    sort(v.begin(), v.end(), cmp);
    vector<pair<string, int> >vv;
    map<string, int>countrywin;
    for(auto it=email.begin(); it!=email.end(); it++){
       countrywin[country[(*it).first] ]+= (*it).second;
    }
    for(auto it=countrywin.begin(); it!=countrywin.end(); it++){
       vv.push_back(make_pair((*it).first , (*it).second));
    }
    sort(vv.begin(), vv.end(), cmp);
    cout<<vv[0].first<<endl;
    cout<<v[0].first<<endl;
}
