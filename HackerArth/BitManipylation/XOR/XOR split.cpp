/*
   You are given a number .
   Your task is to find if there exist two distinct natural numbers such that their bitwise  is  and bitwise  is . 
   If such numbers exist, then print . Otherwise, print .
*/

#include <iostream>
using namespace std;
int main() {
	int t; cin>>t;
	while(t--){
       long long num;
		cin >> num;    
		if(num == 0 || ((num & num-1) == 0))cout<<0<<endl;
		else cout<<1<<endl;
	}
}
