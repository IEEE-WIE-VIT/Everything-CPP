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
#define vi                   vector<int>
#define vb                   vector<bool>
#define vpll                 vector<pair<ll,ll>>
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
#define enter(a)             for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a)              for(ll e: a) cout<<e<<" "; cout<<"\n";
#define all(x)               begin(x), end(x)
#define rep(i, a, b)         for(int i = a; i < (b); ++i)

using namespace std;

ll mo(ll a){ return a%MOD;}

ll po(ll x, ll y, ll p)
{
    ll res = 1; x = x % p;   
    while (y > 0) { if (y & 1) res = (res * x) % p; y >>= 1; x = (x * x) % p; } 
    return res%p; 
}

struct suf_ar
{
    string s;
    ll n;
    void init(string a, vll &p, vll &lcp)
    {
        s = a;
        s += '$';
        n = s.size();
        find_suf(p);
        find_lcp(s, p, lcp);
    }

    void count_sort(vll &p, vll &c)
    {
        ll n = p.size();
        vll cnt(n);
    
        for(ll x: c) cnt[x]++;
    
        vll pos(n);
        for(ll i=1;i<n;i++) pos[i] = pos[i-1] + cnt[i-1];
    
        vll new_p(n);
        for(ll x:p)
        {
            ll i = c[x];
            new_p[pos[i]] = x;
            pos[i]++;
        }
    
        p = new_p;
    }

    void find_suf(vll &p)
    {
        p.assign(n, 0);
        vpll pos(n);
        for(ll i=0;i<n;i++) pos[i] = {s[i], i};
        sort(all(pos));

        for(ll i=0;i<n;i++) p[i] = pos[i].second;

        vll c(n);
        for(ll i=1;i<n;i++) c[p[i]] = c[p[i-1]] + (pos[i].first != pos[i-1].first);

        ll k = 0;
        while((1LL<<k) < n)
        {
            for(ll i=0;i<n;i++) p[i] = (p[i] - (1<<k) + n)%n;

            count_sort(p, c);
 
            vll c_new(n);
            for(ll i=1;i<n;i++)
            {
                pll prev = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
                pll now = {c[p[i]], c[(p[i] + (1<<k))%n]};
    
                c_new[p[i]] = c_new[p[i-1]] + (now != prev);
            }
            c = c_new;
            k++;
        }
    }

    void find_lcp(string const& s, vll const& p, vll &lcp) 
    {
        int n = s.size();
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            rank[p[i]] = i;

        int k = 0;
        lcp.assign(n -1 , 0);
        
        for (int i = 0; i < n; i++) 
        {
            if (rank[i] == n - 1) 
            {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < n && j + k < n && s[i+k] == s[j+k])
                k++;
            lcp[rank[i]] = k;
            if (k)
                k--;
        }
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}   