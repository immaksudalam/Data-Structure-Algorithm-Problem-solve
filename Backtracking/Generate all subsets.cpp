#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;

void helper(vector<int>&v, vector<int>&cur, int pos){

    ans.push_back(cur);
    for(int i = pos; i<v.size(); i++){
        cur.push_back(v[i]);
        helper(v, cur, i+1);
        cur.pop_back();
    }
}
int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int>cur;
    helper(v, cur, 0);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
}
