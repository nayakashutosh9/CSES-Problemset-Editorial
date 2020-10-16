/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-16 18:22]
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
vector<string> a;
vvi dist;
vector<vector<pii>> par;
int dx[4] = {0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0};
void solve() {
	cin >> n >> m;
	clr(a, n);
	for (int i = 0; i < n; i++) cin >> a[i];
	dist.clear(); dist.resize(n, vi(m, inf));
	par.clear(); par.resize(n, vector<pii>(m, { -1, -1}));
	int sx = -1, sy = -1, ex = -1, ey = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'A') sx = i, sy = j;
			if (a[i][j] == 'B') ex = i, ey = j;
		}
	}
	if (sx == -1 || ex == -1) {
		cout << "NO\n";
		return;
	}
	bool found = 0;
	queue<pii> q; q.push({sx, sy}); dist[sx][sy] = 0;
	while (!q.empty()) {
		pii f = q.front(); q.pop();
		for (int r = 0; r < 4; r++) {
			int g = f.ff + dx[r], h = f.ss + dy[r];
			if (g >= 0 && h >= 0 && g < n && h < m && a[g][h] != '#' && (1 + dist[f.ff][f.ss]) < dist[g][h]) {
				dist[g][h] = 1 + dist[f.ff][f.ss];
				q.push({g, h});
				par[g][h] = {f.ff, f.ss};
				if (g == ex && h == ey) {
					found = 1;
					break;
				}
			}
		}
		if (found) break;
	}
	if (dist[ex][ey] == inf) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n" << dist[ex][ey] << endl;
	string ans = string(dist[ex][ey], 'L');
	int curx = ex, cury = ey, id = dist[ex][ey] - 1;
	while (curx != sx || cury != sy) {
		int px = par[curx][cury].ff, py = par[curx][cury].ss;
		if (px == curx) {
			if (py == cury + 1) ans[id--] = 'L';
			else ans[id--] = 'R';
		}
		else {
			if (px == curx + 1) ans[id--] = 'U';
			else ans[id--] = 'D';
		}
		curx = px, cury = py;
	}
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