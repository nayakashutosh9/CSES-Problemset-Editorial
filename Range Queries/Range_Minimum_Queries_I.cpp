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
 *	created: [2020-12-23 23:18]
 *	"Compete against yourself"
**/

const int N = 3e5 + 5, M = 24;
int n, q;
vi a;
struct sparse {
	vi p2;
	vvi mat;
	int n, m;
	void init(int _n, int _m) {
		n = _n, m = _m;
		p2.clear(); p2.resize(n + 1, 0);
		mat.clear(); mat.resize(n, vi(m, 0));
		for (int i = 2; i <= n; i++) p2[i] = p2[i / 2] + 1;
		for (int i = 0; i < n; i++) mat[i][0] = a[i];
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				if ((i + (1 << j)) <= n) mat[i][j] = min(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1]);
				else break;
			}
		}
	}
	int query(int l, int r) {
		int v = p2[r - l + 1];
		return min(mat[l][v], mat[r - (1 << v) + 1][v]);
	}
};
void solve() {
	cin >> n >> q;
	clr(a, n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sparse s;
	s.init(n, 1 + log2(n));
	while (q--) {
		int l, r; cin >> l >> r;
		cout << s.query(l - 1, r - 1) << endl;
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