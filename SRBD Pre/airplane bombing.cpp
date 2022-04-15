#include <bits/stdc++.h>
using namespace std;
int rows, ans;
int grid[100][5];
bool boomUsed=false;

void sol(int i, int j, int cost){
	if(j<0 || j>=5) return;
	if(i == rows){
		ans = max(ans, cost);
		return;
	}
	bool flag = false;
	int ctr = 0;
	int enemy[30][2];
	if(grid[i][j] == 2){
		if(boomUsed){
			ans = max(ans, cost);
			return;
		}
		else{
			flag = true;
			boomUsed = true;
			for(int r = i; r<min(i+5, rows); r++){
				for(int c = 0; c<5; c++){
					if(grid[r][c] == 2){
						grid[r][c] = 0;
						enemy[ctr][0] = r;
						enemy[ctr++][1] = c;
					}
				}
			}
		}
	}
	else if(grid[i][j] == 1){
		cost++;
	}
	sol(i+1, j, cost);
	sol(i+1, j+1, cost);
	sol(i+1, j-1, cost);
	
	if(flag){
		boomUsed= false;
		for(int k=0; k<ctr; k++){
			int x = enemy[k][0];
			int y = enemy[k][1];
			grid[x][y] = 2;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	int temp = 1;
	while(t--){
		cin>>rows;
	    for(int i=0; i<rows; i++){
		  for(int j=0; j<5; j++){
			cin>>grid[rows-i-1][j];
		}
	}
	ans = INT_MIN;
	sol(0, 1, 0);
	sol(0, 2, 0);
	sol(0, 3, 0);
	cout<<"#"<<temp++<<" "<<ans<<endl;
 }
	
	return 0;
}
