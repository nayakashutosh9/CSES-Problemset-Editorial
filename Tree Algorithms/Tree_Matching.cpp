/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-11-07 13:18]
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
const int N = 3e5 + 5;
int n;
vi g[N];
int dp[N][2];
int dfs(int node, int par, int prev) {
	if (dp[node][prev] != -1) return dp[node][prev];
	int cur = 0, r;
	mii vis;
	for (int j : g[node]) {
		if (j != par) {
			int x = dfs(j, node, 0);
			vis[j] = x;
			cur += x;
		}
	}
	r = cur;
	if (prev == 1) return r;
	for (int j : g[node]) {
		if (j != par) {
			int x = dfs(j, node, 1);
			r = max(r, cur - vis[j] + x + 1);
		}
	}
	return dp[node][prev] = r;
}
void solve() {
	cin >> n;
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	memset(dp, -1, sizeof(dp));
	int ans = dfs(1, 0, 0);
	cout << ans << endl;
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