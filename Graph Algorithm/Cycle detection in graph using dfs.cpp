#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>graph[], int src,int parent, vector<int>&vis){
	vis[src] = 1;
	
	for(auto it: graph[src]){
		if(vis[it] == -1){
			if(dfs(graph, it, parent, vis)) return true;
		}
		if(it != parent) return true;
	}
	return false;
}

bool isCycle(int node, vector<int>graph[]){
	vector<int>vis(node+1, -1);
	for(int i=1; i<=node; i++){
		if(vis[i] == -1){
			if(dfs(graph, i, -1, vis)) return true;
		}
	}
	return false;
}
int main()
{
	int node, edge;
	cin>>node>>edge;
	vector<int>graph[edge+1];
	for(int i=0; i<edge; i++){
		int a, b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	bool ans = isCycle(node, graph);
	if(ans){
		cout<<"cycle detected"<<endl;
	}
	else cout<<"cycle not detected"<<endl;
}
