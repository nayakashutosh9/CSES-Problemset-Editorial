/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-16 23:56]
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
vector<string> a;
int dx[4] = {0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0};
string ans;
vvi dist;
// void dfs(int i, int j, string path) {
// 	if (ans != "NO") return;
// 	vis[i][j] = 1;
// 	if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && ans == "NO") ans = path;
// 	for (int r = 0; r < 4; r++) {
// 		int g = i + dx[r], h = j + dy[r];
// 		if (g >= 0 && h >= 0 && g < n && h < m && a[g][h] == '.' && !vis[g][h] && dist[g][h] > 1 + path.length()) {
// 			char v;
// 			if (dx[r] == 0) {
// 				if (dy[r] == -1) v = 'L';
// 				else v = 'R';
// 			}
// 			else {
// 				if (dx[r] == -1) v = 'U';
// 				else v = 'D';
// 			}
// 			dfs(g, h, path + v);
// 		}
// 	}
// 	vis[i][j] = 0;
// }
void solve() {
	cin >> n >> m;
	a.clear(); a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ans = "NO";
	int sx = -1, sy = -1;
	dist.clear(); dist.resize(n, vi(m, inf));
	queue<pii> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'A') sx = i, sy = j;
			if (a[i][j] == 'M') q.push({i, j}), dist[i][j] = 0;
		}
	}
	while (!q.empty()) {
		pii f = q.front(); q.pop();
		for (int r = 0; r < 4; r++) {
			int g = f.ff + dx[r], h = f.ss + dy[r];
			if (g >= 0 && h >= 0 && g < n && h < m && a[g][h] == '.' && (1 + dist[f.ff][f.ss]) < dist[g][h]) {
				dist[g][h] = 1 + dist[f.ff][f.ss];
				q.push({g, h});
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) cout << ((dist[i][j] == inf) ? -1 : dist[i][j]) << " ";
	// 	cout << endl;
	// }
	// dfs(sx, sy, "");
	while (!q.empty())
		q.pop();
	vvi vis(n, vi(m, inf));
	vector<vector<pii>> par(n, vector<pii>(m, { -1, -1}));
	q.push({sx, sy}); par[sx][sy] = {0, 0}; vis[sx][sy] = 0;
	int dtx = -1, dty = -1;
	while (!q.empty()) {
		pii f = q.front(); q.pop();
		if (f.ff == 0 || f.ff == n - 1 || f.ss == 0 || f.ss == m - 1) {
			dtx = f.ff; dty = f.ss;
			break;
		}
		for (int r = 0; r < 4; r++) {
			int g = f.ff + dx[r], h = f.ss + dy[r];
			if (g >= 0 && h >= 0 && g < n && h < m && a[g][h] == '.' && (1 + vis[f.ff][f.ss]) < vis[g][h] && (1 + vis[f.ff][f.ss]) < dist[g][h]) {
				vis[g][h] = 1 + vis[f.ff][f.ss];
				q.push({g, h});
				par[g][h] = f;
			}
		}
	}
	if (dtx == -1) cout << "NO\n";
	else {
		cout << "YES\n" << vis[dtx][dty] << endl;
		if (!vis[dtx][dty]) return;
		ans = string(vis[dtx][dty], 'L');
		int cur = ans.length() - 1;
		int curx = dtx, cury = dty;
		while (curx != sx || cury != sy) {
			int px = par[curx][cury].ff, py = par[curx][cury].ss;
			if (px == curx) {
				if (cury == py + 1) ans[cur--] = 'R';
				else ans[cur--] = 'L';
			}
			else {
				if (curx == px + 1) ans[cur--] = 'D';
				else ans[cur--] = 'U';
			}
			curx = px, cury = py;
		}
		cout << ans << endl;
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