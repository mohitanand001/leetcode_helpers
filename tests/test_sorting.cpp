#include<bits/stdc++.h>
#include "../sorting/sorting_for_testing.cpp"
using namespace std;

// vector<int> sortor(vector<int> &v);

int main()
{
  vector<int> v = {5,1,2,53,112,231,1-12};
  vector<int> tmp = v;
  
  tmp = sortor(tmp);
  assert(v == tmp);
  return 0;
}

