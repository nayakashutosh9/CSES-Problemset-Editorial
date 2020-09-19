/**
 *  author: nayakashutosh9
 *	[2020-09-18 23:40]
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int 		long long int
#define endl 		'\n'
#define mod 		1000000007
#define modd		998244353
#define inf 		1e18
#define ff 			first
#define ss 			second
#define pb 			push_back
#define pii 		pair<int,int>
#define mii 		map<int,int>
#define vi 			vector<int>
#define sz(x) 		(int)x.size()
#define all(x) 		x.begin(),x.end()
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/

vi a;
bool check(int key, int n, int t) {
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += (key / a[i]);
		if (cur >= t) return true;
	}
	return cur >= t;
}
void solve() {
	int n, t; cin >> n >> t;
	a.clear(); a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int lo = 0, hi = (*min_element(all(a))) * t, mid, ans = 0;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid, n, t)) {
			ans = mid; hi = mid - 1;
		}
		else lo = mid + 1;
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
		// cout << "Case #" << (i++) << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
		//print execution time in ms
	}

	return 0;
}