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
	string s; cin >> s;
	int n = s.length();
	vector<int> f(26, 0);
	for (char i : s) f[i - 'A']++;
	int odd = 0;
	for (int i = 0; i < 26; i++) odd += (f[i] % 2 == 1);
	if (odd > 1) {
		cout << "NO SOLUTION\n";
		return;
	}
	int i = 0, j = n - 1;
	while (i < j) {
		for (int k = 0; k < 26; k++) {
			if (f[k] >= 2) {
				s[i++] = (char)('A' + k);
				s[j--] = (char)('A' + k);
				f[k] -= 2;
				break;
			}
		}
	}
	if (i == j) {
		for (int k = 0; k < 26; k++) {
			if (f[k] > 0) {
				s[i++] = (char)('A' + k);
				break;
			}
		}
	}
	cout << s << endl;
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