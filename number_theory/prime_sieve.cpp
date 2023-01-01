// https://leetcode.com/problems/closest-prime-numbers-in-range/submissions/869189283/
// https://www.youtube.com/watch?v=pKvGYOnO9Ao&ab_channel=TECHDOSE
#include <bits/stdc++.h>
using namespace std;

vector<bool> isprime(int N)
{
  vector<bool> prime (N + 1, true);
  prime[0] = prime[1] = false;
  
  for(long long i = 2; i * i <= N; i++)
  {
    if(prime[i])
    {
      for(long long j = i * i; j <= N; j +=i)
      {
        prime[j] = false;
      }
    }
  }
  
  return prime;
}

int main()
{
  return 0;
}
