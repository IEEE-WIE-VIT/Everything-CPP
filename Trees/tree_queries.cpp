//https://codeforces.com/contest/1328/problem/E

#include<bits/stdc++.h>
 
using namespace std;
 
 
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
void INIT()
{
 
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
//-----------------------------------------------------------------------------------------------------------------
 
vector<int> adj[200001];
int parent[200001][21];
int lev[200001];
 
void dfs(int node, int par, int level)
{	lev[node] = level;
	parent[node][0] = par;
	for (int i = 0; i < 20; i++)
	{
		parent[node][i + 1] = parent[parent[node][i]][i];
 
	}
 
	for (auto it : adj[node])
	{
		if (it != par)
		{
			dfs(it, node, level + 1);
		}
	}
}
 
int solve(int node, int k)
{
	for (int i = 0; i < 20; i++)
	{
		if (k & (1 << i))
		{
			node = parent[node][i];
 
		}
	}
	return node;
}
 
 
 
int lca(int u, int v)
{
	if (lev[v] < lev[u])
		swap(u, v);
 
	int dist = lev[v] - lev[u];
 
	v = solve(v, dist);
	if (u == v)
		return u;
	else
	{
		for (int i = 17; i >= 0; i--)
		{
			if (parent[u][i] != parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		return parent[u][0];
	}
}
 
int distance(int a, int k)
{
	int boss = lev[a] + lev[k] - 2 * lev[lca(a, k)];
	return boss;
}
signed main()
{
	INIT();
	int n;
	cin >> n;
	int q;
	cin >> q;
	int u, v;
	for (int i = 0; i < n - 1   ; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
 
 
	dfs(1, 0, 1);
 
	while (q--)
	{
		int m;
		cin >> m;
		vector<int>b;
		int deepest = 0;
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			if (lev[x] > lev[deepest])
				deepest = x;
			b.push_back(x);
		}
		debug(b);
		int flag = 1;
		for (auto it : b)
 
 
		{
			int check = lca(it, deepest);
			if ( check == it || distance(it, check) == 1)
			{
				flag = 1;
 
 
			}
			else
			{
				flag = 0;
				break;
			}
 
		}	if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
 
 
	}
 
 
}
 
 
