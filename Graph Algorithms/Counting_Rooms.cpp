/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-16 14:05]
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
vector<string> a;
vector<vector<bool>> vis;
int n, m;
int dx[4] = {0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0};
void dfs(int i, int j) {
	vis[i][j] = 1;
	for (int r = 0; r < 4; r++) {
		int g = i + dx[r], h = j + dy[r];
		if (g >= 0 && h >= 0 && g < n && h < m && a[g][h] == '.' && !vis[g][h]) dfs(g, h);
	}
}
void solve() {
	cin >> n >> m;
	clr(a, n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vis.clear(); vis.resize(n, vector<bool>(m, 0));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.' && !vis[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
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