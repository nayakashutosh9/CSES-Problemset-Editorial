/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-11 14:10]
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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define clr(x,n) x.clear();x.resize(n)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
int n, req;
int dp[501][125251][2];
int powmod(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans % mod;
}
int check(int i, int sum, int prev) {
	if (sum > (req / 2)) return 0;
	if (i > n) return sum == (req / 2);
	if (dp[i][sum][prev] != -1) return dp[i][sum][prev];
	int q = 0;
	q = (q + check(i + 1, sum, 0)) % mod;
	q = (q + check(i + 1, sum + i, 1)) % mod;
	return dp[i][sum][prev] = q % mod;
}
void solve() {
	cin >> n;
	req = n * (n + 1) / 2;
	if (req % 2) {
		cout << "0\n";
		return;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 1 + (req / 2); j++) dp[i][j][0] = dp[i][j][1] = -1;
	}
	int ans = (check(1, 0, 0)) % mod;
	ans = ((ans % mod) * (powmod(2, mod - 2)) % mod) % mod;
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