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
 *	created: [2020-12-24 19:18]
 *	"Compete against yourself"
**/

const int N = 3e5 + 5;
int n, m;
vi h, r;
struct segment_tree_max {
	vi tree;
	int n;
	void init(int _n) {
		n = _n;
		tree.clear(); tree.resize(4 * n + 1, 0);
	}
	void build(int index, int s, int e) {
		if (s > e) return;
		if (s == e) {
			tree[index] = h[s];
			return;
		}
		int mid = (s + e) / 2;
		build(2 * index, s, mid);
		build(2 * index + 1, mid + 1, e);
		tree[index] = max(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int index, int s, int e, int id, int val) {
		if (s > e) return;
		if (s > id || e < id) return;
		if (s == e) {
			h[s] -= val;
			tree[index] = h[s];
			return;
		}
		int mid = (s + e) / 2;
		update(2 * index, s, mid, id, val);
		update(2 * index + 1, mid + 1, e, id, val);
		tree[index] = max(tree[2 * index], tree[2 * index + 1]);
	}
	int query(int index, int s, int e, int l, int r) {
		if (s > e) return -inf;
		if (s > r || e < l) return -inf;
		if (s >= l && e <= r) return tree[index];
		int mid = (s + e) / 2;
		int left = query(2 * index, s, mid, l, r);
		int right = query(2 * index + 1, mid + 1, e, l, r);
		return max(left, right);
	}
};
void solve() {
	cin >> n >> m;
	clr(h, n); clr(r, m);
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < m; i++) cin >> r[i];
	segment_tree_max s;
	s.init(n);
	s.build(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int lo = 0, hi = n - 1, mid, ans = -1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (s.query(1, 0, n - 1, 0, mid) >= r[i]) {
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		if (ans == -1) cout << "0 ";
		else {
			cout << ans + 1 << " ";
			s.update(1, 0, n - 1, ans, r[i]);
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