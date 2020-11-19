#include <bits/stdc++.h>
using namespace std;
set<int> subarrays;
int findans(int x){ // the second type of query
    //for any element k, the first element in the subarray of element k is-
    // the largest j in subarray such j<=k
    //Find the first element j such that j>k
    //j--
    auto it = subarrays.upper_bound(x);
    it--;
    return (*it);
}
void remove(int x){
     subarrays.erase(x);
}
int main()
{
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    subarrays.insert(1); //subarray must be start from element 1
    for(int i=2; i<=n; i++){
        if(arr[i]%arr[i-1]==0)continue; //this element lies previous subarras
        subarrays.insert(i); // create a new subarray
    }
    while(q--){
        int type, i;
        cin>>type>>i;
        if(type==1){
           cin>>arr[i]; // the updated value of a[i]
           // there are 4 thing that can happen
           // a[i] and a[i-1] can now be in the same subarray
           // a[i] and [i-1] are no longer the same subarray
           // a[i] and a[i+1] can now be in the same subarray
           // a[i] and a[i+1] are no longer the same subarray
           if(i>1){
                if((findans(i)==i) && (arr[i]%arr[i-1]==0)){ // arr[i] & arr[i] are in the same subarray
                    remove(i);
                }
                else if((findans(i) < i) && (arr[i]%arr[i-1]!=0)){
                    // earlier they are in the same subarray. but now they are no longer in the same subarray
                    subarrays.insert(i);
                }
           }
           if(i<n){
              if((findans(i+1) > i)&& (arr[i+1] % arr[i]==0)){
                 // these element weren't in the same subarray. but now they are in the same subarray
                 remove(i+1);
              }
              else if((findans(i+1) <= i) && (arr[i+1]%arr[i]!=0)){
                // these element were in the same subarray. but now they are no longer in the same subarray
                subarrays.insert(i+1);
              }
           }
        }
        else{
             cout<<findans(i)<<endl;
        }
    }
}
