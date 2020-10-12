/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-13 01:48]
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
int n; bool dp[101][100001];
vi a;

void solve() {
	cin >> n;
	clr(a, n);
	int s = 0;
	for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
	sort(all(a));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= s; j++) dp[i][j] = 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i][j] |= dp[i - 1][j];
			if (j >= a[i - 1]) dp[i][j] |= dp[i - 1][j - a[i - 1]];
		}
	}
	vi ans;
	for (int i = 1; i <= s; i++) {
		if (dp[n][i]) ans.pb(i);
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