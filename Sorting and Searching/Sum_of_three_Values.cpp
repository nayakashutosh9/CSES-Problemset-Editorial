/**
 *  author: nayakashutosh9
 *	[2020-09-19 02:42]
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


void solve() {
	int n, x; cin >> n >> x;
	vector<pii> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].ff, a[i].ss = i;
	sort(all(a));
	for (int i = 0; i < n - 2; i++) {
		int l = i + 1, r = n - 1;
		int req = x - a[i].ff;
		while (l < r) {
			int s = a[l].ff + a[r].ff;
			if (s == req) {
				cout << a[i].ss + 1 << " " << a[l].ss + 1 << " " << a[r].ss + 1 << endl;
				return;
			}
			else if (s > req) r--;
			else l++;
		}
	}
	cout << "IMPOSSIBLE\n";
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