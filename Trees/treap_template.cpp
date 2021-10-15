#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#include<cmath>
#include<stack>
#include<map> 
#define ll                   long long
#define skip                 cin>>ws;
#define vll                  vector<ll> 
#define vb                   vector<bool>
#define vpll                 vector<pair<ll,ll>>
#define vi                   vector<int>
#define vpi                  vector<pair<int, int>>
#define vvll                 vector<vector<ll>>
#define vvi                  vector<vector<int>>
#define vvvll                vector<vector<vector<ll>>>
#define pll                  pair<ll,ll>
#define vs                   vector<string>
#define vvpll                vector<vector<pair<ll, ll>>>
#define vvpi                 vector<vector<pair<int, int>>>
#define pb                   push_back
#define pob                  pop_back()
#define MOD                  (ll)(1e9 + 7)
#define MOD2                 (ll)(998244353)
#define INF                  (ll)(1e18 + 5)
#define count1(n)            __builtin_popcountll(n)
#define test                 ll t; cin>>t; while(t--)
#define all(x)               begin(x), end(x)
#define sz(x)                (int)x.size()

using namespace std;

ll inline mo(ll a){ return a%MOD;}
ll po(ll x, ll y, ll p)
{
    ll res = 1; x = x % p;   
    while (y > 0) { if (y & 1) res = (res * x) % p; y >>= 1; x = (x * x) % p; } 
    return res%p; 
}

template<typename T>
void inline enter(vector<T> &a){ for(T &e: a) cin>>e; } 

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#include <chrono>
#include <random>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
/* 
    Don't forget to override '<=', '<'.
*/

template<class D>
class treap
{
    D neutral;

    public:

	struct data
	{
		int priority, cnt;
        D val;
		data *l, *r;
 
	 	data()
	 	{
	 		cnt = 0, l = NULL, r = NULL; val = NULL;
	 	}
 
		data (D val)
		{
		    cnt = 1;
            this->val = val;
			l = NULL, r = NULL;
			priority = getRand(1, 2e9);
		}
	};
 
	typedef struct data* node;
	 
	node head; 
 
	treap(D neutral): head(0), neutral(neutral)  {}
 
	int cnt(node cur)
	{
		return cur ? cur->cnt : 0;
	}
	 
	void updateCnt(node cur)
	{
		if(cur)
			cur->cnt = cnt(cur->l) + cnt(cur->r) + 1;
	}
 
	void prop(node cur) //Lazy Propagation
 	{
		 if(!cur) return ;
	}
	 
	void combine(node &cur, node l, node r)
	{
		if(!l)
		{
			cur = r;
			return;
		}
		if(!r)
		{
			cur = l;
			return;
		}
		//Merge Operations like in segment tree

		// To be done
	}
 	 	
	void reset(node &cur) //To reset other fields of cur except indices and cnt
	{
		if(!cur)
			return;
	}
 
	void operation(node &cur)
	{
		if(!cur)
			return;
		reset(cur);
		combine(cur, cur->l, cur);
		combine(cur, cur, cur->r);

        /* Can also write segment tree updates here */
	}
 
    // 0 - indexed

	void split_pos(node cur, node &l, node &r, int k, int add = 0)
	{
		if(!cur)
			return void(l = r = 0);
		prop(cur);

		int idx = add + cnt(cur->l);
		if(idx <= k)
			split_pos(cur->r, cur->r, r, k, idx + 1), l = cur;
		else
			split_pos(cur->l, l, cur->l, k, add), r = cur;

		updateCnt(cur);
		operation(cur);
	}
 
    // 1 - indexing on k

	void split(node cur, node &l, node &r, D k)
	{
		if(!cur)
			return void(l = r = 0);

		// lazy propagation
		prop(cur);

        D idx = cur->val;

        // '<=' is overriden
        if(idx <= k)
            split(cur->r, cur->r, r, k), l = cur;
        else
            split(cur->l, l, cur->l, k), r = cur;
		
        updateCnt(cur);
		operation(cur);
	}

    
    void just_less(node cur, node &l, node &r, D val)
    {
        if(!cur)
			return void(l = r = 0);

		// lazy propagation
		prop(cur);
				
        D idx = cur->val, k = val;

        // earlier '<=' for removing equal elements
        if(idx < k)
            just_less(cur->r, cur->r, r, k), l = cur;
        else
            just_less(cur->l, l, cur->l, k), r = cur;
		
        updateCnt(cur);
		operation(cur);
    }
	 
	void merge(node &cur, node l, node r)
	{
		// max heap type merging

		prop(l);
		prop(r);

		if(!l || !r)
			cur = l ? l : r;
		else if(l->priority > r->priority)
			merge(l->r, l->r, r), cur = l;
		else
			merge(r->l, l, r->l), cur = r;
		updateCnt(cur);
		operation(cur);
	}
	 
	// !!! Important: This insert is removing equal elements

	void insert(D val)
	{
		if(!head)
		{
			head = new data(val);
			return;
		}

		node l, r, mid, mid2, rr;
		mid = new data(val);

		just_less(head, l, r, mid->val);
		merge(l, l, mid);

        /* Removing equal element */
		split(r, mid2, rr, mid->val);
		merge(head, l, rr);
	}
	 
	void erase(D val)
	{
		node l, r, mid;
		just_less(head, l, r, val);
		split(r, mid, r, val);
		merge(head, l, r);
	}
 
	void clear(node cur)
	{
		if(!cur)
			return;
		clear(cur->l), clear(cur->r);
		delete cur;
	}
 
	void clear()
	{
		clear(head);
	}
 
	D find_by_order(int x) //1 indexed
	{
		if(!x)
			return neutral;
		x--;
		node l, r, mid;
		split_pos(head, l, r, x - 1);
		split_pos(r, mid, r, 0);
		D ans = neutral;
		if(cnt(mid) == 1)
			ans = mid->val;
		merge(r, mid, r);
		merge(head, l, r);
		return ans;
	}
 
	int order_of_key(D val) //1 indexed
	{
		node l, r, mid;
		just_less(head, l, r, val);
		split(r, mid, r, val);
		int ans = -1;
		if(cnt(mid) == 1)
			ans = 1 + cnt(l);
		merge(r, mid, r);
		merge(head, l, r);
		return ans;
	}

	void inorder(node cur)
	{
		if(!cur) return;
		prop(cur);
		inorder(cur->l);
		cout<<(cur->val.first)<<" "<<cur->val.second<<"\n";
		inorder(cur->r);
	}

	void inorder()
	{
		inorder(head);
	}
};

int main()
{
    vpll a = {{9, 1}, {-100, 2}, {4, 0}, {-100, 3}, {5, 5}, {4, 0}};

    treap<pll> tr({-1, -1});
    
    for(pll e: a) tr.insert(e);
    tr.inorder();

    // cout<<tr.order_of_key({9, 1})<<"\n";
    // cout<<tr.order_of_key({0, 0})<<"\n";
    pll res = tr.find_by_order(4);
    cout<<"{ "<<res.first<<", "<<res.second<<"} "<<"\n";

    tr.erase({5, 5});

    cout<<"\n";

    tr.inorder();
    tr.erase({100, 100});

    cout<<"\n";
    tr.inorder();

    // res = tr.find_by_order(4);
    // cout<<"{ "<<res.first<<", "<<res.second<<"} "<<"\n";

}
