#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define endl '\n'
#define mod 1000000007
//#define mod 998244353
#define inf 1e18
#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define clr(x,n) x.clear();x.resize(n,0)
#define precise(x) fixed<<setprecision(x)
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;

/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-12-24 20:14]
 *	"Compete against yourself"
**/

const int N = 5e5 + 5;
int n, q;
vi a;
void solve() {
	cin >> n >> q;
	clr(a, n);
	pbds s;
	for (int i = 0; i < n; i++) cin >> a[i], s.insert({a[i], i});
	while (q--) {
		char c; cin >> c;
		if (c == '!') {
			int k, x; cin >> k >> x;
			s.erase({a[k - 1], k - 1});
			a[k - 1] = x;
			s.insert({a[k - 1], k - 1});
		}
		else {
			int l, r; cin >> l >> r;
			int ans = 0;
			ans += s.order_of_key({r + 1, 0});
			ans -= s.order_of_key({l, 0});
			cout << ans << endl;
		}
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
	int T = 1;
	//cin >> T; cin.ignore();
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
	}

	return 0;
}