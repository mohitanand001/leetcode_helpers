// not verified, verify it once by passing thought any leetcode soln

#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<bool> &vis, vector<vector<int> > &gr)
{
  queue<int> q;
  q.push(src);
  vis[src] = true;
  
  while(!q.empty())
  {
    int fr = q.front();
    q.pop();
    
    for(int i = 0; i < gr[fr].size(); i++)
    {
      if(!vis[gr[fr][i]])
      {
        q.push(gr[fr][i]);
        vis[gr[fr][i]] = true;
      }
    }
    
  }
}


int main()
{
  int ne, n;
  cin >> ne >> n;
  vector<vector<int> > gr(n, vector<int> ()) ;
  vector<bool> vis (n, false);
  int x, y;
  for(int i = 0; i < ne; i++)
  {
    cin >> x >> y;
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  
  for(int i = 0; i < n; i++)
  {
    if(vis[i] == false)
    {
      bfs(i, vis, gr);
    }
  }
  
  return 0;
}
