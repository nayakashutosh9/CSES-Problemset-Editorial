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
 *	created: [2020-12-24 13:08]
 *	"Compete against yourself"
**/

const int N = 3e5 + 5;
int n, q;
vector<string> a;
struct prefix_sums_matrix {
	int n, m;
	vvi pre;//1-based indexing
	void init(int _n, int _m) {
		n = _n, m = _m;
		pre.clear(); pre.resize(n + 1, vi(m + 1, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) pre[i + 1][j + 1] = (a[i][j] == '*');
		}
	}
	void calc() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			}
		}
	}
	int query(int x1, int y1, int x2, int y2) {
		int ans = 0;
		// cout << pre[x2][y2] << " " << pre[x1 - 1][y2] << " " << pre[x2][y1 - 1] << " " << pre[x1 - 1][y1 - 1] << endl;
		ans += pre[x2][y2];
		ans -= pre[x1 - 1][y2];
		ans -= pre[x2][y1 - 1];
		ans += pre[x1 - 1][y1 - 1];
		return ans;
	}
};
void solve() {
	cin >> n >> q;
	a.clear(); a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	prefix_sums_matrix p;
	p.init(n, n);
	p.calc();
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << p.query(x1, y1, x2, y2) << endl;
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