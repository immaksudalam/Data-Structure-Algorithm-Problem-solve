#include <bits/stdc++.h>
using namespace std;
int x[4] = {1, -1, 0 , 0};
int y[4] = {0, 0, 1, -1};

int main()
{
	int n, m;
	cin>>n>>m;
	pair<int, int>start, end;
	vector<vector<char> >grid(n+1, vector<char>(m+1));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>grid[i][j];
			if(grid[i][j] == 'A') start = {i, j};
			if(grid[i][j] == 'B') end = {i, j};
		}
	}
    vector<vector<int> >vis(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++)
       for(int j=1; j<=m; j++) vis[i][j]=-1;
    
    vector<vector<pair<int, int> > >path(n+1, vector<pair<int, int> >(m+1));
    
    queue<pair<int, int> >q;
    q.push(start);
    bool flag = false;
    
    while(!q.empty()){
    	int xx = q.front().first;
    	int yy = q.front().second;
    	q.pop();
    	
    	for(int i=0; i<4; i++){
    		int xxx = xx + x[i];
    		int yyy = yy + y[i];
    		if(xxx>=1 && xxx <=n && yyy>=1 && yyy<=m && vis[xxx][yyy] == -1 && grid[xxx][yyy] == '.'){
    			q.push({xxx, yyy});
    			path[xxx][yyy] = {xx, yy};
    			vis[xxx][yyy] = 1;
			}
			if(make_pair(xxx, yyy) == end){
				path[xxx][yyy] = {xx, yy};
				flag = true;
				break;
			}
			if(flag){
				break;
			}
		}
	}
    if(!flag){
    	cout<<"NO"<<endl;
    	return 0;
	}
	else{
		int x = end.first;
		int y = end.second;
		string s = "";
		while(make_pair(x, y) != start){
			int xx = path[x][y].first;
			int yy = path[x][y].second;
			if(xx -1 == x && yy == y) s+= "U";
			else if(xx+1 == x && yy == y) s+= "D";
			else if(xx == x && yy -1 == y) s+= "L";
			else if(xx == x && yy+1 == y) s+= "R";
			
			x = xx;
			y = yy;
		}
		reverse(s.begin(), s.end());
		cout<<"YES"<<endl;
		cout<<s.size()<<endl;
		cout<<s<<endl;
	}
    
}
