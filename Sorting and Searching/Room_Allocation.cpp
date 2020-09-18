/**
 *  author: nayakashutosh9
 *	[2020-09-18 01:22]
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

struct cmp {
	bool operator()(pair<pii, int> a, pair<pii, int> b) {
		if (a.ff.ff == b.ff.ff) return a.ff.ss < b.ff.ss;
		return a.ff.ff < b.ff.ff;
	}
};

void solve() {
	int n; cin >> n;
	vector<pair<pii, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].ff.ff >> a[i].ff.ss;
		a[i].ss = i;
	}
	sort(all(a), cmp());
	vi ans(n, 1);
	set<pii> vis;
	set<int> av;
	for (int i = 0; i < n; i++) {
		// cout << a[i].ff.ff << " " << a[i].ff.ss << endl;
		while (!vis.empty() && (*vis.begin()).ff < a[i].ff.ff)
			av.insert(ans[a[(*vis.begin()).ss].ss]), vis.erase(vis.begin());
		vis.insert({a[i].ff.ss, i});
		if (!av.empty()) ans[a[i].ss] = *av.begin(), av.erase(av.begin());
		else ans[a[i].ss] = sz(vis);
	}
	cout << *max_element(all(ans)) << endl;
	for (int i : ans) cout << i << " ";
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