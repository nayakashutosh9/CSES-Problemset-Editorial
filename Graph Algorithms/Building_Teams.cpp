/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-16 23:22]
 *	"Compete against yourself"
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define endl '\n'
#define mod 1000000007
#define modd 998244353
#define inf 1e18
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define clr(x,n) x.clear();x.resize(n,0)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
int n, m;
vi g[N];
bool oddCycle;
vi vis;
void dfs(int node, int col) {
	vis[node] = col;
	for (int j : g[node]) {
		if (vis[j] == -1) {
			dfs(j, 3 - col);
		}
		else if (vis[j] == vis[node]) oddCycle = true;
	}
}
void solve() {
	cin >> n >> m;
	vis.clear(); vis.resize(n + 1, -1);
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	oddCycle = false;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == -1) dfs(i, 1);
	}
	if (oddCycle) cout << "IMPOSSIBLE\n";
	else {
		for (int i = 1; i <= n; i++) cout << vis[i] << " ";
		cout << endl;
	}
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T; cin.ignore();
	for (int i = 1; i <= T; i++) {
		// cout << "Case #" << i << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
		//print execution time in ms
	}

	return 0;
}