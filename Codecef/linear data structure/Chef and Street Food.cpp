#include <bits/stdc++.h>
using namespace std;
int main()
{
   vector<int>vec;
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      for(int i=0; i<n; i++){
         int s, p, v;
         cin>>s>>p>>v;
         s++;
         int t = (p/s)*v;
         vec.push_back(t);
      }
      sort(vec.begin(), vec.end());
      cout<<vec[n-1]<<endl;
   }

}
