#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char> >&grid, vector<vector<int> >&vis, int i, int j, int n, int m){
	if(i<1 || i>n || j<1 || j>m || vis[i][j] == 1 || grid[i][j]=='#') return;
	if(grid[i][j] == '#') return;
  
	vis[i][j] = 1;
	dfs(grid, vis, i+1, j, n, m);
	dfs(grid, vis, i-1, j, n, m);
	dfs(grid, vis, i, j+1, n, m);
	dfs(grid, vis, i, j-1, n, m);
	
}
int main()
{
	int n, m;
	cin>>n>>m;
	vector<vector<char> >grid(n+1, vector<char>(m+1));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>grid[i][j];
		}
	}
    vector<vector<int> >vis(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++)
       for(int j=1; j<=m; j++) vis[i][j]=-1;
    
    int cnt =0;
    
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=m; j++){
    		if(grid[i][j]== '.' && vis[i][j]==-1){
    			cnt++;
    			
    			dfs(grid, vis, i, j, n, m);
			}
		}
	}
	cout<<cnt<<endl;
    
}
