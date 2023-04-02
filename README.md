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

### Random questions
1. Minimum number of operations to make all the numbers in an array equal, if in a single operation
we can increase or decrease the elements.
sort the array
take the median, then calculate the sum of abs(median - arr[i]) to find the 


### Sliding windows
1. whenever there is a question for subarrays think about sliding window. If the question is to find number of subarrays with 
   at least X (>= X), find the number of subarrays with > X, and then subtract from total number of subarrays possible.
   https://leetcode.com/contest/weekly-contest-328/problems/count-the-number-of-good-subarrays/
   
2. To find the window of size k with the maximum product in an array, you can use a sliding window approach. Here's one way to implement it in C++,all numbers are greater than 0, and we need to just have the range of subarray, not the actual product.
```cpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> maxProductSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    double maxLogProd = -INFINITY;
    int left = 0, right = 0;
    double currLogProd = 0;

    while (right < n) {
        currLogProd += log(nums[right]);
        if (right - left + 1 == k) {
            if (currLogProd > maxLogProd) {
                maxLogProd = currLogProd;
                left++;
            } else {
                currLogProd -= log(nums[left]);
                left++;
            }
        }
        right++;
    }

    int start = left - k;
    int end = left - 1;
    return make_pair(start, end);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    pair<int, int> range = maxProductSubarray(nums, k);
    cout << "Subarray range with maximum product: [" << range.first << ", " << range.second << "]" << endl;
    return 0;
}

```

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
