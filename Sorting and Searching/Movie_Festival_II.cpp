/**
 *  author: nayakashutosh9
 *	[2020-09-23 13:44]
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

struct cmp {
	bool operator()(pii a, pii b) {
		if (a.ss == b.ss) return a.ff < b.ff;
		return a.ss < b.ss;
	}
};
void solve() {
	int n, k; cin >> n >> k;
	vector<pii> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].ff >> a[i].ss;
	multiset<int> s;
	for (int i = 0; i < k; i++) s.insert(0);
	sort(all(a), cmp());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto x = s.upper_bound(a[i].ff);
		if (x != s.begin()) {
			x = prev(x);
			ans++;
			s.erase(x);
			s.insert(a[i].ss);
		}
		else continue;
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