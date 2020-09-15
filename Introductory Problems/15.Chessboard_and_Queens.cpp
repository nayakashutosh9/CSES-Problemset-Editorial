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
vector<string> a;
int ans;
bool pos(int i, int j) {
	for (int x = 0; x < i; x++) {
		if (a[x][j] == 'q') return false;
	}
	int x = i - 1, y = j - 1;
	while (x >= 0 && y >= 0) {
		if (a[x][y] == 'q') return false;
		x--; y--;
	}
	x = i - 1; y = j + 1;
	while (x >= 0 && y < 8) {
		if (a[x][y] == 'q') return false;
		x--; y++;
	}
	return true;
}
bool check(int i) {
	if (i == 8) {
		ans++;
		return false;
	}
	for (int j = 0; j < 8; j++) {
		if (a[i][j] == '*') continue;
		if (pos(i, j)) {
			a[i][j] = 'q';
			bool r = check(i + 1);
			if (r) return true;
			a[i][j] = '.';
		}
	}
	return false;
}
void solve() {
	a.clear(); a.resize(8);
	for (int i = 0; i < 8; i++) cin >> a[i];
	ans = 0;
	check(0);
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