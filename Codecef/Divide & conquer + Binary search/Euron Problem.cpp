#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right){
    int i,j,k;
    i = left; // i to locate first array location
    j = mid; // i to locate second array location
    k = left; // i to locate merged array location
    ll cnt = 0;
    while((i<= mid -1) && (j<= right)){
        if(arr[i] <= arr[j]){ // when left item is less than right item
            temp[k++] = arr[i++];

        }
        else{
            temp[k++] = arr[j++];
            cnt += (mid - i);
        }
    }

    while(i<= mid -1){ // if first list has remaining item, add them in temp array
        temp[k++]= arr[i++];
    }
    while(j <= right){ // if second list has remaining item, add them in temp array
        temp[k++]= arr[j++];
    }
    for(int i= left; i<=right; i++){
        arr[i]=temp[i];// store temp array to main array.
    }
    return cnt;
}
ll mergeSort(ll arr[], ll temp[], ll left, ll right){
    ll mid;
    ll cnt =0;
    if(right > left){
        mid = (left+right)/2;
        cnt+= mergeSort(arr, temp, left, mid);
        cnt += mergeSort(arr, temp, mid+1, right);
        cnt += merge(arr, temp, left, mid+1, right);
    }
   return cnt;
}
ll arrInversion(ll arr[], ll n){
    ll temp[n];
    return mergeSort(arr, temp, 0, n-1);
}
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++) cin>>arr[i];
    cout<<arrInversion(arr, n)<<endl;
}

