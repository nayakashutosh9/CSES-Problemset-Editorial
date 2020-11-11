/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-11-05 23:55]
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
int n, m, mx;
vi g[N], par;
void path(int cur) {
	if (par[cur] == 0) {cout << cur << " "; return;}
	path(par[cur]);
	cout << cur << " ";
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
	}
	par.clear(); par.resize(n + 1, 0);
	vi d(n + 1, -inf);
	d[1] = 0;
	queue<pii> q;
	q.push({0, 1});
	while (!q.empty()) {
		pii f = q.front(); q.pop();
		for (int j : g[f.ss]) {
			if ((1 + f.ff) > d[j]) {
				d[j] = 1 + f.ff;
				if (d[j] > 0) {
					q.push({d[j], j});
					par[j] = f.ss;
				}
			}
		}
	}
	if (d[n] < 1) {cout << "IMPOSSIBLE\n"; return;}
	cout << d[n] + 1 << endl;
	path(n);
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