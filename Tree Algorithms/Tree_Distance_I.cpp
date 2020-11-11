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
 *	created: [2020-11-10 14:00]
 *	"Compete against yourself"
**/

const int N = 3e5 + 5;
int n;
vi g[N], ans, h;
int height(int node, int par) {
	h[node] = 1;
	int mx = 0;
	for (int j : g[node]) {
		if (j != par) mx = max(mx, height(j, node));
	}
	h[node] += mx;
	return h[node];
}
void dfs(int node, int par, int cur) {
	vi b;
	b.pb(0);
	for (int j : g[node]) {
		if (j != par) b.pb(h[j]);
	}
	sort(all(b));
	int len = sz(b);
	ans[node] = max(cur, b[len - 1]);
	for (int j : g[node]) {
		if (j != par) {
			if (h[j] == b[len - 1]) {
				int next = max(cur, b[len - 2]);
				dfs(j, node, next + 1);
			}
			else {
				int next = max(cur, b[len - 1]);
				dfs(j, node, next + 1);
			}
		}
	}
}
void solve() {
	cin >> n;
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	ans.clear(); ans.resize(n + 1, 0);
	h.clear(); h.resize(n + 1, 0);
	height(1, 0);
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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