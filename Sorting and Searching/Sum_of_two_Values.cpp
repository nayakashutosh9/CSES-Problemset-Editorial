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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	map<int, int> vis;
	int p = -1, q = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if ((k - a[i]) > 0 && vis.count(k - a[i])) {
			p = vis[k - a[i]]; q = i + 1;
		}
		if (!vis.count(a[i])) vis[a[i]] = i + 1;
	}
	if (p != -1 && q != -1) cout << p << " " << q << endl;
	else cout << "IMPOSSIBLE\n";
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