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
	int n, y; cin >> y >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	map<int, int> m;
	set<pair<int, int>> vis;
	vis.insert({0, a[0]}); vis.insert({a[0], y});
	m[a[0]]++; m[y - a[0]]++;
	cout << m.rbegin()->first << " ";
	for (int i = 1; i < n; i++) {
		auto z = vis.upper_bound({a[i], a[i] - 1});
		z = prev(z);
		pair<int, int> x = *z;
		m[x.second - x.first]--;
		if (m[x.second - x.first] == 0) m.erase(x.second - x.first);
		vis.insert({x.first, a[i]});
		vis.insert({a[i], x.second});
		vis.erase(z);
		m[a[i] - x.first]++; m[x.second - a[i]]++;
		cout << m.rbegin()->first << " ";
	}
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