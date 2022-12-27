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

bool compare(pair<int, int> &p1, pair<int, int> &p2)
{
	if(p1.first == p2.first)
        return p1.second < p2.second;

    return p1.first < p2.first;
}

vector<int> sortor(vector<int> &v)
{
	sort(v.begin(), v.end());
	return v;
}

int main()
{
	
	vector<node> vec = {node(1, 2), node(10, 3), node(5, 11), node(3, 11), node(8, 11)};
	// sorting using operator overloading
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size(); i++)
	{
		cout << "x=" << vec[i].x << " " << endl;
	}
	cout << endl;
	

	// sort using comparator
	vector<pair<int, int> > v2 = {{4,1}, {2,4}, {1,3}, {3,1}, {1,5}};
	

	sort(v2.begin(), v2.end(), compare);
	

	for(int i = 0; i < v2.size(); i++)
	{
		cout << v2[i].first << " " << v2[i].second << endl;
	}
	
	cout << endl;

	// sort using lambda
	vector<pair<int, int> > v3 = {{4,1}, {2,4}, {1,3}, {3,1}, {1,5}};
	sort(v3.begin(), v3.end(), [&](pair<int, int> a, pair<int, int> b){
		if(a.first == b.first)
			return a.second < b.second;
		return a.first < b.first;
	});

	for(int i = 0; i < v3.size(); i++)
	{
		cout << v3[i].first << " " << v3[i].second << endl; 
	}


	// sort an array by its frequency, if same freq, the bigger number occurs first

	vector<int> v4 = {3,4,5, 5, 2,1,1,1,2,2,2,2};
	unordered_map<int, int> mp;
	for(auto x: v4)
	{
		mp[x]++;
	}

	sort(v4.begin(), v4.end(), [&](int a, int b){
		if(mp[a] == mp[b])
			return a > b;
		return mp[a] < mp[b];
	});

	cout << endl;
	for(int i = 0; i < v4.size(); i++)
	{
		cout << v4[i] << endl;
	}
 
	return 0;
}

// Output
// x=1 
// x=3 
// x=5 
// x=8 
// x=10 
