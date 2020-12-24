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
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;

/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-12-24 12:37]
 *	"Compete against yourself"
**/

const int N = 3e5 + 5;
int n, q;
vi a;
struct fenwick_tree_sum {
	vi bit;
	int n;
	void init(int _n) {
		n = _n;
		bit.clear(); bit.resize(n + 5, 0);
	}
	void update(int i, int val) {
		while (i <= n) {
			bit[i] += val;
			i += (i & (-i));
		}
	}
	void build() {
		for (int i = 1; i <= n; i++)
			update(i, a[i - 1]);
	}
	int query(int i) {
		int ans = 0;
		while (i > 0) {
			ans += bit[i];
			i -= (i & (-i));
		}
		return ans;
	}
	void print() {
		for (int i = 1; i <= n; i++) cout << query(i) << " ";
		cout << endl;
	}
};
void solve() {
	cin >> n >> q;
	clr(a, n);
	for (int i = 0; i < n; i++) cin >> a[i];
	fenwick_tree_sum f;
	f.init(n);
	// f.build();
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, v, w; cin >> u >> v >> w;
			f.update(u, w);
			f.update(v + 1, -w);
			continue;
		}
		int l; cin >> l;
		cout << a[l - 1] + f.query(l) << endl;
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