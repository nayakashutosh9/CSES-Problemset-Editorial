/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-11-05 20:29]
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
/*******************************************************/
const int N = 1e5 + 5;
int n, m;
vi g[N], par;
vector<bool> instack, vis;
vi ans;
void dfs(int node, int p) {
	if (sz(ans) > 0) return;
	par[node] = p;
	vis[node] = 1;
	instack[node] = 1;
	for (int j : g[node]) {
		if (sz(ans) > 0) return;
		if (!vis[j]) dfs(j, node);
		else if (instack[j]) {
			int cur = node;
			while (cur != j) {
				ans.pb(cur);
				cur = par[cur];
			}
			ans.pb(j);
			reverse(all(ans));
			ans.pb(j);
			return;
		}
	}
	instack[node] = 0;
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
	}
	par.clear(); par.resize(n + 1, 0);
	instack.clear(); instack.resize(n + 1, 0);
	vis.clear(); vis.resize(n + 1, 0);
	ans.clear();
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && sz(ans) == 0) dfs(i, 0);
	}
	if (sz(ans) == 0) cout << "IMPOSSIBLE";
	else {
		cout << sz(ans) << endl;
		for (int i : ans) cout << i << " ";
	}
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