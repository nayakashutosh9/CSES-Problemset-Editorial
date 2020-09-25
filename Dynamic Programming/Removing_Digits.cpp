/**
 *  author: nayakashutosh9
 *	[2020-09-25 19:36]
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
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
vector<bool> vis;
int dp[1000001];
int check(int n) {
	if (n == 0) return 0;
	if (n < 0) return 2000000;
	if (dp[n] != -1) return dp[n];
	int q = 2000000;
	int p = n;
	for (int i = 0; i < 10; i++) vis[i] = 0;
	while (p) {
		vis[p % 10] = 1; p /= 10;
	}
	for (int i = 9; i > 0; i--) {
		if (vis[i]) q = min(q, 1 + check(n - i));
	}
	return dp[n] = q;
}
void solve() {
	int n; cin >> n;
	vis.clear(); vis.resize(10, 0);
	for (int i = 0; i <= n; i++) dp[i] = -1;
	check(n);
	cout << dp[n] << endl;
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