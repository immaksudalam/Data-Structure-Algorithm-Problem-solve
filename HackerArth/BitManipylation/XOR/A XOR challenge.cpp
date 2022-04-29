/*
  You would need basic XOR concept to understand this problem. The XORed result has either two kind of bits in binary representation.
If ith bit is 0 in C then ith bit of A & B should be either 0 or 1 in both the integers. Since we need maximized product so we will 
always set ith bit = 1 in A & B whenever ith bit is 0 in C.
Now interesting case comes when ith bit is 1 in C. We know that either one of A & B has ith bit set and other unset. If you list put 
every possible combinations you will notice that the sum of A & B remains constant. And when sum of A & B is constant we get maximum 
product when A & B are at close to each other.
Eg A+B = 6.
Possible Combinations :
A  B Product
1  5   5
2  4   8
3  3   9
So we get max product 9 when A and B are very close to each other. 
So to make A & B close to each other, we apply greedy approach and it goes as follows :
For MSB set bit in C we will set that bit in A and for all the other set bit in C, we will make that bit set in B. So that A and B are close to
each other and product maximises.
      a^b = c
	a^a^b = a^c
	b = a^c

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll c;
    cin>>c;
    int len=0;
    ll temp = c;
    while(c){
        len++;
        c = c>>1;
    }
    ll a = pow(2, len-1)-1;
    ll b = a^temp;
    cout<<a*b<<endl;
}
