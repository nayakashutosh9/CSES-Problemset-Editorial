/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-23 13:10]
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
#define precise(x) fixed<<setprecision(x)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
vector<pii> g[2505];
int n, m;

void solve() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) g[i].clear();
	vvi edges;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		g[x].pb({y, w});
		edges.pb({x, y, w});
	}
	vi dist(n + 1, inf), par(n + 1, -1);
	dist[1] = 0; par[1] = 1;
	int cur = -1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = edges[j][0], v = edges[j][1], w = edges[j][2];
			if (dist[u] != inf && dist[u] + w < dist[v]) {
				par[v] = u;
				dist[v] = dist[u] + w;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int u = edges[j][0], v = edges[j][1], w = edges[j][2];
		if (dist[u] != inf && dist[u] + w < dist[v]) {
			par[v] = u;
			dist[v] = dist[u] + w;
			cur = v;
		}
	}
	if (cur == -1) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		cur = par[cur];
	}
	vi ans;
	int req = cur;
	while (1) {
		ans.pb(cur);
		if (sz(ans) > 1 && cur == req) {
			break;
		}
		cur = par[cur];
	}
	reverse(all(ans));
	cout << "YES\n";
	for (int i : ans) cout << i << " ";
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