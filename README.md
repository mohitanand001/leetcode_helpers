# leetcode_helpers
![main](https://github.com/mohitanand001/leetcode_helpers/actions/workflows/main.yml/badge.svg) <br>
[emaxx algorithms notebook](https://cp-algorithms.com/)

### TODO

- [ ] Topo sort (DFS)
- [ ] Topo sort (BFS)
- [ ] Dijkstra
- [x] BFS (level order, and normal)
- [x] sorting comparator
- [x] heap with comparator and custom data type
<!-- - [ ]  -->


Observations: 
### DP
1. If the state table has negative values, let's say `dp[i][j]` can have values like -1, -2, to denote an invalid state either use
   `dp[i][j] = INT_MIN` or to be safe use a diff `vector<vector<bool> > vis` and set `vis[i][j] = false` to denote an invalid state.
