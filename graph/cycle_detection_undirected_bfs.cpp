// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int parent, int src, vector<bool> &vis, vector<int> g[])
    {
    	
    	queue<int> q;
    	vector<int> par(vis.size(), -1);
    	
    	par[src] = parent;
    	vis[src] = true;
    	q.push(src);
    	
    	while(!q.empty())
    	{
    		int fr = q.front();
    		q.pop();
    		

    		for(int i = 0; i < g[fr].size(); i++)
    		{
    		    
    			if(vis[g[fr][i]] == false)
    			{
    				vis[g[fr][i]] = true;
    				par[g[fr][i]] = fr;
    				q.push(g[fr][i]);
    			}
    			else 
    			{
    				if(g[fr][i] != par[fr])
    					return true;
    			}
    		}
    	}
    	
    	
    	return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis (V, false);
        for(int i = 0; i < V;i++)
        {
            if(vis[i] == false)
            {
                if(bfs(-1, i, vis, adj))
                    return true;
            }
        }
        
        return false;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
