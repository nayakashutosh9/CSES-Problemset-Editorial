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
 *	created: [2020-11-11 23:29]
 *	"Compete against yourself"
**/

const int N = 3e5 + 5;
int n;
vi g[N], d, sub, ans;
pii dfs(int node, int par) {
	sub[node] = 0;
	d[node] = 0;
	for (int j : g[node]) {
		if (j != par) {
			pii f = dfs(j, node);
			sub[node] += f.ff;
			d[node] += f.ss;
		}
	}
	d[node] += sub[node];
	sub[node] += 1;
	return {sub[node], d[node]};
}
void getAns(int node, int par, int cur) {
	cur += (n - sub[node]);
	ans[node] = cur + d[node];
	for (int j : g[node]) {
		if (j != par) cur += (d[j] + sub[j]);
	}
	for (int j : g[node]) {
		if (j != par) {
			getAns(j, node, cur - (d[j] + sub[j]));
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
	d.clear(); d.resize(n + 1, 0);
	sub.clear(); sub.resize(n + 1, 0);
	ans.clear(); ans.resize(n + 1, 0);
	dfs(1, 0);
	getAns(1, 0, 0);
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