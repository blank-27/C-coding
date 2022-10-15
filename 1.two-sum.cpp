#include <bits/stdc++.h>
#define ll long long
using namespace std;

int wt[10][10];
map<int,int> m;

void solve() {
	int x,y;
	x = 10;
	y = 9;
	cout<<x<<y;
}

void printpath(vector<int>& path)
{
	int size = path.size();
	int prev=path[0];
	cout<<prev<<" ";
	int sim = 0;
	for (int i = 1; i < size; i++){
		cout << path[i] << " ";
		sim+=wt[prev][path[i]];
		prev=path[i];
	}
	m[sim]++;
	// cout<<sim;
	cout << endl;
	cout<<sim;
	cout << endl;
}

	int isNotVisited(int x, vector<int>& path)
	{
		int size = path.size();
		for (int i = 0; i < size; i++)
			if (path[i] == x)
				return 0;
		return 1;
	}

void findpaths(vector<vector<int> >&g, int src,int dst, int v)
{
	queue<vector<int> > q;

	vector<int> path;
	path.push_back(src);
	q.push(path);
	while (!q.empty()) {
		path = q.front();
		q.pop();
		int last = path[path.size() - 1];

		if (last == dst)
			printpath(path);	

		for (int i = 0; i < g[last].size(); i++) {
			if (isNotVisited(g[last][i], path)) {
				vector<int> newpath(path);
				newpath.push_back(g[last][i]);
				q.push(newpath);
			}
		}
	}
}

// driver program
int main()
{
	vector<vector<int> > g;
	// number of vertices
	int v = 4;
	g.resize(4);

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			wt[i][j]=-1;
		}
	}

	// construct a graph
	g[0].push_back(3);
	wt[0][3]=3-0;

	g[0].push_back(1);
	wt[0][1]=1-0;
	g[0].push_back(2);
	wt[0][2]=2-0;
	g[1].push_back(3);
	wt[1][3]=3-1;
	g[2].push_back(0);
	wt[2][0]=2;
	g[2].push_back(1);
	wt[2][1]=1;

	int src = 2, dst = 3;
	cout << "path from src " << src
		<< " to dst " << dst << " are \n";

	// function for finding the paths
	findpaths(g, src, dst, v);
	for(auto it:m){
		cout<<it.first<<" "<<it.second<<endl;
	}

	return 0;
}
