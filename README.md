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


### Number Theory
1. There is at max 1 prime divisor of a greater than sqrt(n), in which case the number n is prime.
   Proof by contracdition, if there are 2 prime divisors of n, greater than sqrt(n), lets say X and Y.
   The prime factorization of n will be p1 * p2 * p3 * X * p4 * Y * .. * pk
   if we multiply them i.e. X*Y, we will get a number bigger than n, since X (> sqrt(n)) * Y > (sqrt(n)) => XY (> n).
   Notice that we cannot say the same thing about the "divisor" of a number.
   ex: n = 36,sqrt(n) = 6, we have 4 divisors of 36, i.e. 9, 12, 18 and 36 which are >= 6. 


### STL
1. map<int, int> mp; 
   auto it = mp.begin(); it is an iterator(sort of a wrapper around the pointer)
   to get the value of it just do *it, which will give what's stored at that location.
   since map has value stored as pair<key, value>, you'll get a pair<key, val>;
   ```cpp
   map<int, int> mp;
   auto it = mp.begin();
   pair<int, int> element = *it;
   cout << element.first << " " << element.second << endl;
   cout << (*it).first << " " << (*it).second << endl; //we've a shorthand for this line
   cout << it->first << " " << it->second << endl;
   ````
 2. auto x inside a for loop takes the value stored in the data structure, in the following x is an integer.
      ```cpp
      vector<int> nums;
      for(auto x: nums)
      {
         cout << x << " " << endl;
      }
      ```

      The following 2 are equivalent code
      ```cpp
      map<int, int> mp;
      for(auto [fi, se]: mp)
      {
         cout << fi <<" " << se << endl;
      }

      for(auto x: mp)
      {
         cout << x.first <<" " << x.second  << endl;
      }
    ```
