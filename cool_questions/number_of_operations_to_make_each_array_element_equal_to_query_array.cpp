// https://leetcode.com/contest/weekly-contest-338/problems/minimum-operations-to-make-all-array-elements-equal/

// This is a C++ implementation of an optimized solution to the problem. The algorithm is similar to the optimized version I provided earlier, but with some minor changes.

// The code first sorts the nums array and calculates the prefix sum of the sorted array. Then, for each query, it uses the lower_bound function to find the position of the query in the sorted nums array. If the query is larger than all elements in the array, it calculates the total number of operations required by subtracting the prefix sum of the entire array from the product of the query and the length of the array.

// Otherwise, it calculates the number of operations required to make all elements of the nums array equal to the query by counting the number of elements greater than the query (more variable) and the number of elements less than the query (less variable). The total number of operations required is the sum of more and less.

// Here's the breakdown of the time complexity:

//     Sorting the nums array takes O(n log n) time.
//     Calculating the prefix sum of the sorted array takes O(n) time.
//     For each query, finding the position of the query in the sorted array using lower_bound takes O(log n) time. Calculating the number of operations required takes O(1) time.
//     Therefore, the total time complexity is O(n log n + m log n).

// Overall, this implementation is quite efficient and should be able to handle large input sizes.



// Sure! Let me explain the calculation for each query in detail.

// First, we use the lower_bound function to find the position of the query in the sorted nums array. This returns an iterator pointing to the first element in the array that is not less than the query. We subtract the beginning iterator of the nums array from this iterator to get the index of the first element in the array that is not less than the query. This index is stored in the variable low.

// If low equals the size of the nums array, then the query is larger than all elements in the array. In this case, we need to increase all elements of the array to the value of the query. The total number of operations required to do this is simply the product of the query and the length of the array minus the sum of all elements in the array. This is because we can increase each element in the array by the difference between the query and the element, and the sum of all these differences is equal to the product of the query and the length of the array minus the sum of all elements in the array.

// If low is less than the size of the nums array, then we need to make all elements of the nums array equal to the query. We can do this by making all elements less than the query equal to the query and all elements greater than or equal to the query equal to the query. To calculate the number of operations required, we need to count the number of elements less than the query and the number of elements greater than the query.

// To count the number of elements less than the query, we calculate the sum of all elements less than low and subtract it from low times the query. This is because we can increase each element less than the query by the difference between the query and the element, and the sum of all these differences is equal to low times the query minus the sum of all elements less than low.

// To count the number of elements greater than the query, we calculate the sum of all elements greater than or equal to low and subtract it from the sum of all elements in the array plus the value of the element at index low times the number of elements greater than or equal to low. This is because we can decrease each element greater than or equal to the query by the difference between the query and the element, and the sum of all these differences is equal to the sum of all elements in the array plus the value of the element at index low times the number of elements greater than or equal to low, minus the sum of all elements greater than or equal to low.

// Finally, we add the counts of elements less than and greater than the query to get the total number of operations required to make all elements of the nums array equal to the query.

vec = [1, 5, 7, 8, 11, 24], if q[i] = 40, then number of operations is

(40- 1) + (40 - 5) + (40-7) + (40-8) + (40 - 11) + (40 - 24) = 40 * 6 - perfix_sum[6 - 1]

vec = [1, 5, 7, 8, 11, 24], if q[i] = 8,then number of operations is
(8 - 1) + (8 - 5) + (8 - 7) + (8 - 8) + (11 - 8) + (24 - 8) = (8 * 4 - prefix_sum[4]) + ((prefix_sum[6 - 1] - prefix_sum[3]) - 8 * 2)


class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        
        std::sort(nums.begin(), nums.end());
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;
        }
        
        int m = queries.size();
        vector<long long> res(m, 0);
        
        for (int i = 0; i < m; ++i) {
            long long q = queries[i];
            long long low = std::lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            if (low == nums.size()) {
                res[i] = q * n - prefix[n - 1];
                continue;
            }
            
            long long more = (prefix[n - 1] - prefix[low] + nums[low]) - (n - low) * q;
            long long less = low * q - (prefix[low] - nums[low]);
            
            res[i] = more + less;
        }
        
        return res;
    }
};
