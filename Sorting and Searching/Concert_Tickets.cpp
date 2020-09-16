/*****************************************************
 *     created by: nayakashutosh9
 * "Winners Never Quit and Quitters Never Win".
*****************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define endl '\n'
#define mod 1000000007
#define inf 1e18
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int N = 300005;
/**********************************************************************************************/


void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	multiset<int> s;
	for (int i = 0; i < n; i++) cin >> a[i], s.insert(a[i]);
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < m; i++) {
		auto x = s.upper_bound(b[i]);
		if (x != s.begin()) {
			x = prev(x);
			cout << *x << endl;
			s.erase(x);
			continue;
		}
		cout << "-1\n";
	}
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1, z = 1;
	// cin >> t; cin.ignore();
	while (t--) {
		// cout << "Case #" << (z++) << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
		//print execution time in ms
	}

	return 0;
}