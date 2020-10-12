/**
 *  author: nayakashutosh9
 *	[2020-10-04 00:52]
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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define clr(x,n) x.clear();x.resize(n)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
int n, m;
vi a;
int dp[100001][101];
int check(int i, int prev) {
	if (i == n) return 1;
	if (dp[i][prev] != -1) return dp[i][prev];
	int q = 0;
	if (a[i] == 0) {
		for (int j = 1; j <= m; j++) {
			a[i] = j;
			if (i > 0 && abs(a[i - 1] - j) <= 1) q = (q + check(i + 1, j)) % mod;
			if (i == 0) q = (q + check(i + 1, j)) % mod;
			a[i] = 0;
		}
	}
	else {
		if (i > 0 && abs(a[i - 1] - a[i]) > 1) return 0;
		q = (q + check(i + 1, prev)) % mod;
	}
	return dp[i][prev] = q % mod;
}
void solve() {
	cin >> n >> m;
	clr(a, n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) {
		if (a[0] == 0) cout << m << endl;
		else cout << "1\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 101; j++) dp[i][j] = -1;
	}
	int ans = check(0, 0) % mod;
	cout << ans % mod << endl;
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