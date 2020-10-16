/**
 *  author: Ashutosh Nayak (@nayakashutosh9)
 *	created: [2020-10-16 13:48]
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
#define clr(x,n) x.clear();x.resize(n)
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> pbds;
const int N = 300005;
/*******************************************************/
int dp[501][501];
int check(int a, int b) {
	if (a == b) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	int q = inf;
	for (int i = 1; i < a; i++) {
		q = min(q, 1 + check(i, b) + check(a - i, b));
	}
	for (int i = 1; i < b; i++) {
		q = min(q, 1 + check(a, i) + check(a, b - i));
	}
	return dp[a][b] = q;
}
void solve() {
	int a, b; cin >> a >> b;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) dp[i][j] = -1;
	}
	cout << check(a, b) << endl;
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