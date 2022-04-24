//greek for greeks
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int>dist(n, INT_MAX);
	    dist[0]=0;
	    for(int i=0; i<n-1; i++){
	        for(auto node:edges){
	            int src = node[0];
	            int des = node[1];
	            int wt = node[2];
	            if(dist[src] != INT_MAX){ //to avoid int overflow
	                dist[des] = min(dist[des], dist[src]+wt);
	            }
	        }
	    }
	    //final relaxation
	    for(auto node:edges){
	        int src = node[0];
	        int des = node[1];
	        int wt = node[2];
	        if(dist[src] != INT_MAX && dist[des] > dist[src]+wt)
	           return 1;
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
