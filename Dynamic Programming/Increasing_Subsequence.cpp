/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-06 12:36]
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
#define clr(x,n) x.clear();x.resize(n,0)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/

int n; vi a, bit;

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans = max(ans, bit[i]);
		i -= (i & (-i));
	}
	return ans;
}
void update(int i) {
	int cur = query(i - 1);
	while (i < n + 5) {
		bit[i] = max(bit[i], 1 + cur);
		i += (i & (-i));
	}
}
void solve() {
	cin >> n; clr(a, n + 1);
	map<int, vi> m;
	for (int i = 1; i <= n; i++) cin >> a[i], m[a[i]].pb(i);
	clr(bit, n + 5);
	int cur = 1, r = 1;
	for (auto x : m) {
		for (int j : x.ss) a[j] = r;
		r++;
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, 1 + query(a[i] - 1));
		update(a[i]);
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