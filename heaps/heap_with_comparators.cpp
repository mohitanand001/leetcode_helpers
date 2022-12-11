#include <bits/stdc++.h>
using namespace std;

struct node
{
	int x;
	int y;
	int val;
	
	node(int x, int y, int val)
	{
		this->x = x;
		this->y = y;
		this->val = val;
	}
	// if it returns true, then push deprioritize the
	// current node, i.e this->node
	bool operator<(const node & n) const {
       return this->val < n.val;
    }
};

int main() {
	// your code goes
	
	priority_queue<node, vector<node> > pq;
	
	pq.push(node(1, 2, 10));
	pq.push(node(2, 3, 5));
	pq.push(node(3, 5, 14));
	pq.push(node(4, 5, -1));
	pq.push(node(1, 1, 3));
	
	
	while(!pq.empty())
	{
		node fr = pq.top();
		pq.pop();
		
		cout << "x " << fr.x << " y " <<fr.y << " val " <<  fr.val << endl;
	}
	
	return 0;
}

// Output
// x=3 y=5 val=14
// x=1 y=2 val=10
// x=2 y=3 val=5
// x=1 y=1 val=3
// x=4 y=5 val=-1
