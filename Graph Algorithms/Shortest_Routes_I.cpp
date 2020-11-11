/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-17 13:29]
 *	"Compete against yourself"
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
#define vvi vector<vi>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define clr(x,n) x.clear();x.resize(n,0)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
unordered_map<int, vector<pii>> g;
int n, m;

void solve() {
	cin >> n >> m;
	g.clear();
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		g[x].pb({y, w});
		// g[y].pb({x, w});
	}
	set<pii> s;
	vi dist(n + 1, inf);
	s.insert({0, 1}); dist[1] = 0;
	while (!s.empty()) {
		auto f = *s.begin();
		int dd = f.ff, node = f.ss;
		s.erase(s.begin());
		for (auto j : g[node]) {
			if ((dd + j.ss) < dist[j.ff]) {
				auto h = s.find({dist[j.ff], j.ff});
				if (h != s.end())
					s.erase(h);
				dist[j.ff] = dd + j.ss;
				s.insert({dist[j.ff], j.ff});
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << dist[i] << " ";
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
		// cout << "Case #" << i << ": ";
		// clock_t start = clock();
		solve();
		// clock_t end = clock();
		// cout << (end-start) << endl;
		//print execution time in ms
	}

	return 0;
}