// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/submissions/869240962/

#include <bits/stdc++.h>
using namespace std;
int get_no_of_prime_divisors(int n)
{
    int cnt = 0;
    int tmp = n;
    for(long long j = 2; j * j <= tmp; j++)
    {
        if(n % j == 0)
        {
            cnt++;
            while(nums[i] and nums[i] % j == 0)
            {
                nums[i] = nums[i] / j;
            }                    

        }
    }
    if(nums[i] > 1)
        cnt++;
}


int main()
{
  cout << get_no_of_prime_divisors(100) << endl;
  
  return 0;
}
