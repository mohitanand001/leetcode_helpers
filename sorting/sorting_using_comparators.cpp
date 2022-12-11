#include <bits/stdc++.h>
using namespace std;

struct node
{
	int x;
	int y;
	
	node(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	
	// if function return true the current node this.node
	// this.node goes before node n
	bool operator<(const node &n) const{
		return x < n.x;
	}
};

int main()
{
	
	vector<node> vec = {node(1, 2), node(10, 3), node(5, 11), node(3, 11), node(8, 11)};

	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size(); i++)
	{
		cout << "x=" << vec[i].x << " " << endl;
	}
	cout << endl;

	return 0;
}

// Output
// x=1 
// x=3 
// x=5 
// x=8 
// x=10 
