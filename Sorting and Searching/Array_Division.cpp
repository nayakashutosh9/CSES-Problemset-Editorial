/**
 *  author: nayakashutosh9
 *	[2020-09-19 20:35]
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

vi a(N);
int check(int key, int n) {
	int cur = 1, s = 0;
	for (int i = 0; i < n; i++) {
		if ((s + a[i]) <= key) s += a[i];
		else {
			s = a[i]; cur++;
		}
	}
	return cur;
}
void solve() {
	int n, k; cin >> n >> k;
	int lo = 0, hi = 0, mid, ans;
	for (int i = 0; i < n; i++) cin >> a[i], hi += a[i], lo = max(lo, a[i]);
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid, n) > k) lo = mid + 1;
		else {
			ans = mid; hi = mid - 1;
		}
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