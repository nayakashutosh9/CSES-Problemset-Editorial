/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-11-05 20:53]
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
vi g[N], od;
vector<bool> vis;
bool pos;
void solve() {
	cin >> n >> m;
	od.clear();
	vi deg(n + 1, 0);
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[y].pb(x);
		deg[x]++;
	}
	vis.clear(); vis.resize(n + 1, 0);
	pos = true;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i), vis[i] = 1;
	}
	while (!q.empty()) {
		int f = q.front(); q.pop();
		od.pb(f);
		for (int j : g[f]) {
			if (!vis[j]) {
				deg[j]--;
				if (deg[j] == 0) q.push(j), vis[j] = 1;
			}
			else {
				pos = false; break;
			}
		}
	}
	reverse(all(od));
	if (sz(od) == n && pos) {
		for (int i : od) cout << i << " ";
	}
	else cout << "IMPOSSIBLE";
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