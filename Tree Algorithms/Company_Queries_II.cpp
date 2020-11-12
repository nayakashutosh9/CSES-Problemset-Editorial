#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define endl '\n'
#define mod 1000000007
//#define mod 998244353
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
#define precise(x) fixed<<setprecision(x)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;

/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-11-12 13:41]
 *	"Compete against yourself"
**/

const int N = 3e5 + 5;
int sp[N][30], m;
vi g[N], dep;
void dfs(int node, int par) {
	if (node != par) dep[node] = 1 + dep[par];
	for (int j : g[node]) {
		if (j != par) dfs(j, node);
	}
}
void calc(int node, int par) {
	sp[node][0] = par;
	for (int i = 1; i <= m; i++) {
		sp[node][i] = sp[sp[node][i - 1]][i - 1];
	}
	for (int j : g[node]) {
		if (j != par) calc(j, node);
	}
}
int lca(int u, int v) {
	if (u == v) return u;
	if (dep[u] < dep[v]) swap(u, v);
	int dif = dep[u] - dep[v];
	for (int i = m; i >= 0; i--) {
		if (dif & (1 << i)) u = sp[u][i];
	}
	if (u == v) return u;
	for (int i = m; i >= 0; i--) {
		if (sp[u][i] != sp[v][i]) {
			u = sp[u][i];
			v = sp[v][i];
		}
	}
	return sp[u][0];
}
void solve() {
	int n, q; cin >> n >> q;
	m = 1 + log2(n);
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 2; i <= n; i++) {
		int par; cin >> par;
		g[par].pb(i);
		g[i].pb(par);
		for (int j = 0; j <= m; j++) sp[i][j] = 0;
	}
	dep.clear(); dep.resize(n + 1, 0);
	dfs(1, 1);
	calc(1, 0);
	while (q--) {
		int u, v; cin >> u >> v;
		cout << lca(u, v) << endl;
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
	//cin >> T; cin.ignore();
	for (int i = 1; i <= T; i++) {
		// cout << "Case #" << i << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
	}

	return 0;
}