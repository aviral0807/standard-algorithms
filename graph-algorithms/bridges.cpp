#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int timer = 0, vis_time[N], low[N];
vector<pair<int, int>> bridges;
vector<int> adj[N];

void dfs(int node, int par = -1) {
	vis_time[node] = low[node] = ++timer;

	for(auto child: adj[node]) {
		if(child != par) {
			if(!vis_time[child]) {
				dfs(child, node);
				low[node] = min(low[child], low[node]);

				if(low[child] > vis_time[node]) {
					bridges.push_back({node, child});
				}
			}
			else {
				low[node] = min(low[node], vis_time[child]);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 1; i <= n; i++) {
		if(!vis_time[i]) {
			dfs(i);
		}
	}

	cout << "Bridges - " << endl;
	for(auto ed: bridges) {
		cout << ed.first << " - " << ed.second << endl;
	}
	

	return 0;
}