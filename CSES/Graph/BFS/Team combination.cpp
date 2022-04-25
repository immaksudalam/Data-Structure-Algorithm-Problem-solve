#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, m;
	cin>>n>>m;
	vector<vector<int> >graph(n+1);
	for(int i=1; i<=m; i++){
			int a, b;
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
	}
	vector<int>vis(n+1, -1);
	vector<int>ans(n+1);
	bool flag = false;
	
	for(int i=1; i<=n; i++){
		if(vis[i] == -1){
			ans[i] = 1;
			queue<int>q;
			q.push(i);
			
			while(!q.empty()){
				int x = q.front();
				q.pop();
				int color = ans[x];
				for(int j=0; j<graph[x].size(); j++){
					int y = graph[x][j];
					if(vis[y] == -1){
						vis[y] = 1;
						q.push(y);
						if(color == 1) ans[y] = 2;
						else ans[y] = 1;
					}
					else{
						if(color == ans[y]){
							flag = true;
							break;
						}
					}
				}
				if(flag){
					break;
				}
			}
		}
		if(flag){
			break;
		}
	}
	if(flag){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		for(int i=1; i<ans.size(); i++){
			cout<<ans[i]<<" ";
		}cout<<endl;
	}
	
}
