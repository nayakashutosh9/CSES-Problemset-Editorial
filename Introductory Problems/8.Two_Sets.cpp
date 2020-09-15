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
	int n; cin >> n;
	if ((n * (n + 1) / 2) % 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if (n % 2 == 0) {
		vector<int> a, b;
		int i = 1, j = n, f = 0;
		while (i < j) {
			if (f == 0) a.push_back(i++), a.push_back(j--), f ^= 1;
			else b.push_back(i++), b.push_back(j--), f ^= 1;
		}
		cout << a.size() << endl;
		for (int i : a) cout << i << " ";
		cout << endl;
		cout << b.size() << endl;
		for (int i : b) cout << i << " ";
		cout << endl;
	}
	else {
		vector<int> a, b;
		a.push_back(1); a.push_back(n - 1); b.push_back(n);
		int i = 2, j = n - 2, f = 0;
		while (i < j) {
			if (f == 0) a.push_back(i++), a.push_back(j--), f ^= 1;
			else b.push_back(i++), b.push_back(j--), f ^= 1;
		}
		cout << a.size() << endl;
		for (int i : a) cout << i << " ";
		cout << endl << b.size() << endl;
		for (int i : b) cout << i << " ";
		cout << endl;
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