/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-16 19:26]
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
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
int n, m;
vi g[N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) g[i].clear();
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	vi dist(n + 1, inf);
	vi par(n + 1, -1);
	dist[1] = 0; par[1] = 0;
	queue<int> q; q.push(1);
	while (!q.empty()) {
		int f = q.front(); q.pop();
		for (int j : g[f]) {
			if (dist[j] > 1 + dist[f]) {
				dist[j] = 1 + dist[f];
				q.push(j);
				par[j] = f;
			}
		}
	}
	if (dist[n] == inf) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	deque<int> ans;
	int cur = n;
	while (cur != 0) {
		ans.push_front(cur);
		cur = par[cur];
	}
	cout << sz(ans) << endl;
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