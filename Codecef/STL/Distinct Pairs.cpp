Simple way to find distinct |A|+|B|-1∣A∣+∣B∣−1 values is to sort both |A|∣A∣ and |B|∣B∣ in ascending order, pair smallest element of one set with all element from the second set and largest element of the second set with all but first element of the first set. This way, we get |B|+(|A|-1) = |A|+|B|-1∣B∣+(∣A∣−1)=∣A∣+∣B∣−1 distinct values which is what we want.
The reason these values are distinct is that x+y < x+zx+y<x+z if y < zy<z. This is happening for all consecutive pairs generated in this manner. Indices can be taken care of using maps or arrays itself.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int in;
    vector<pair<int, int> >a,b;
    for(int i=0; i<n; i++){
        cin>>in;
        a.push_back({in,i});
    }
    for(int i=0; i<m; i++){
        cin>>in;
        b.push_back({in,i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<m; i++) cout<<a[0].second <<" "<<b[i].second<<endl;
    for(int i=1; i<n; i++) cout<<a[i].second <<" "<<b[m-1].second<<endl;

}
