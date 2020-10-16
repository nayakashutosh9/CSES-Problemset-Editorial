/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-16 19:08]
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
#define clr(x,n) x.clear();x.resize(n)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
int n, m;
vi g[N];
vector<bool> vis;
void dfs(int node) {
	vis[node] = 1;
	for (int j : g[node]) {
		if (!vis[j]) dfs(j);
	}
}
void solve() {
	cin >> n >> m;
	vis.clear(); vis.resize(n + 1, 0);
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int prev = -1, cnt = 0;
	vector<pii> ans;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			cnt++;
			if (cnt > 1) ans.pb({prev, i});
			prev = i;
		}
	}
	cout << sz(ans) << endl;
	for (auto x : ans) {
		cout << x.ff << " " << x.ss << endl;
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