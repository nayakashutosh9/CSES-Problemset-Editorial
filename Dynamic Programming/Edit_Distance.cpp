/**
 *  author: nayakashutosh9
 *	[2020-10-04 17:01]
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
string a, b;
int dp[5001][5001], n, m;
int check(int i, int j) {
	if (i == n && j == m) return 0;
	if (i >= n && j < m) return m - j;
	if (j >= m && i < n) return n - i;
	if (dp[i][j] != -1) return dp[i][j];
	int q = n + m;
	if (a[i] == b[j]) {
		q = min(q, check(i + 1, j + 1));
	}
	else {
		q = min(q, 1 + check(i + 1, j + 1));
		q = min(q, 1 + check(i + 1, j));
		q = min(q, 1 + check(i, j + 1));
	}
	return dp[i][j] = q;
}
void solve() {
	cin >> a >> b;
	n = a.length(), m = b.length();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) dp[i][j] = -1;
	}
	cout << check(0, 0) << endl;
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