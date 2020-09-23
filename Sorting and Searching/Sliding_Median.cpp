/**
 *  author: nayakashutosh9
 *	[2020-09-21 14:15]
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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/


void solve() {
	int n, k; cin >> n >> k;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	pbds s;
	int take = k;
	if (k % 2 == 0) take--;
	for (int i = 0; i < k; i++) s.insert({a[i], i});
	for (int i = k; i < n; i++) {
		auto x = s.find_by_order(take / 2);
		cout << x->first << " ";
		s.erase({a[i - k], i - k});
		s.insert({a[i], i});
	}
	auto x = s.find_by_order(take / 2);
	cout << x->first << endl;
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