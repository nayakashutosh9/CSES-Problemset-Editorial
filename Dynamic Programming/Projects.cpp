/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-11 18:16]
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
int n, dp[N][2];
vector<vi> a;
multiset<pii> vis;
int check(int i, int prev) {
	if (i >= n) return 0;
	if (dp[i][prev] != -1) return dp[i][prev];
	int q = 0;
	q = max(q, check(i + 1, 0));
	auto x = vis.lower_bound({a[i][1] + 1, i + 1});
	if (x != vis.end()) q = max(q, a[i][2] + check((*x).ss, 1));
	else q = max(q, a[i][2] + check(n, 1));
	return dp[i][prev] = q;
}
void solve() {
	cin >> n;
	a.clear(); a.resize(n, vi(3));
	for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	sort(all(a));
	for (int i = 0; i < n; i++) vis.insert({a[i][0], i});
	for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1;
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