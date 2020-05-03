#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int timer = 0, vis_time[N], low[N], a_point[N];
vector<int> adj[N];

void dfs(int node, int par = -1) {
	vis_time[node] = low[node] = ++timer;

	int cnt = 0;
	for(auto child: adj[node]) {
		if(child != par) {
			if(!vis_time[child]) {
				dfs(child, node);
				low[node] = min(low[child], low[node]);

				if(par != -1 and low[child] >= vis_time[node]) {
					a_point[node] = 1;
				}
				++cnt;
			}
			else {
				low[node] = min(low[node], vis_time[child]);
			}
		}
	}

	if(par == -1 and cnt > 1) {
		a_point[node] = 1;
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

	for(int i = 1; i <= n; i++) {
		if(a_point[i]) {
			cout << i << " ";
		}
	}

	return 0;
}