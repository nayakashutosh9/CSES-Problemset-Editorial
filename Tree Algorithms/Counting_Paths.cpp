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
 *	created: [2020-11-12 18:22]
 *	"Compete against yourself"
**/

const int N = 3e5 + 5, M = 30;
int n, m;
vi g[N], st;
int par[N][M], dep[N];
void dfs(int node, int p) {
	dep[node] = 1 + dep[p];
	for (int j : g[node]) {
		if (j != p) dfs(j, node);
	}
}
void calc(int node, int p) {
	par[node][0] = p;
	for (int j = 1; j < M; j++) {
		par[node][j] = par[par[node][j - 1]][j - 1];
	}
	for (int x : g[node]) {
		if (x != p) calc(x, node);
	}
}
int lca(int u, int v) {
	if (u == v) return u;
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = M - 1; i >= 0; i--) {
		if ((diff >> i) & 1)
			u = par[u][i];
	}
	if (u == v) return u;
	for (int i = M - 1; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
int predfs(int node, int p) {
	for (int j : g[node]) {
		if (j != p) st[node] += predfs(j, node);
	}
	return st[node];
}
void solve() {
	cin >> n >> m;
	st.clear(); st.resize(n + 1, 0);
	memset(dep, 0, sizeof(dep));
	memset(par, 0, sizeof(par));
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0); calc(1, 0);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		int l = lca(x, y);
		if (l == x || l == y) {
			st[par[l][0]]--;
			if (x != l) st[x]++;
			else st[y]++;
		}
		else {
			st[x]++; st[y]++;
			st[par[l][0]]--; st[l]--;
		}
	}
	predfs(1, 0);
	for (int i = 1; i <= n; i++) cout << st[i] << " ";
	cout << endl;
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