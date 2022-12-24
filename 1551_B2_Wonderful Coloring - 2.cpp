// Author - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef unsigned long long          ull;
typedef vector<ll>                  vll;
typedef vector<string>              vst;
typedef set<ll>                     sll;
typedef map<ll, ll>                 mll;
typedef pair<ll, ll>                pll;
typedef vector<pll>                 vpll;
typedef multiset<ll>                msll;

#define int                     long long
#define rep(i,s,e)              for(ll i=s; i<e; i++)
#define repr(i,s,e)             for(ll i=s; i>=e; i--)
#define repit(it,A)             for(auto it = A.begin();it!=A.end();it++)
#define in(A)                     for(auto &i : A) cin>>i
#define out(A)                     for(auto &i : A) cout<<i<<" "; cout<<endl
#define uniq(A)                 A.erase(unique(all(A)),A.end())
#define all(A)                     A.begin(),A.end()
#define allr(A)                    A.rbegin(),A.rend()
#define pb                         push_back
#define mem1(A)                 memset(A,-1,sizeof(A))
#define mem0(A)                 memset(A,0,sizeof(A))
#define ppcll                     __builtin_popcountll
#define M_PI                     3.14159265358979323846
#define ff                         first
#define ss                         second
#define INF                     1e18
#define sz(A)                     (ll)((A).size())
#define spre(x)                 fixed<<setprecision(x)
#define endl                     '\n'

bool per_square(ld a) { if (a < 0) return false; ll sr = sqrt(a); return (sr * sr == a); }
bool is_prime(ll x) { rep(i, 2, sqrt(x) + 1) if (x % i == 0) return false; return true; }
bool sort_by_sec(const pll &a, const pll &b) { return (a.second < b.second); }
template<typename T>bool is_pali(T A) { int n = sz(A); rep(i, 0, n / 2) { if (A[i] != A[n - i - 1])return 0;} return 1;}
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / (gcd(a, b)); }

ll findGCD(ll A[], ll n)
{
    ll res = A[0];
    rep(i, 1, n)
    {
        res = gcd(A[i], res);
        if (res == 1)
            return 1;
    }
    return res;
}

const ll M = 1e9 + 7;
// const ll M = 998244353;
ll mod(ll a) {return ((a + M) % M);}
ll mod_add(ll a, ll b) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}
ll mod_mul(ll a, ll b) {a = a % M; b = b % M; return (((a * b) % M) + M) % M;}
ll mod_sub(ll a, ll b) {a = a % M; b = b % M; return (((a - b) % M) + M) % M;}
ll mod_pow(ll a, ll b) {ll t = 1; while (b > 0) {if (b & 1) t = (t * a) % M; b /= 2; a = (a * a) % M;} return t % M;}

ll setBit (ll n, ll x) { return n | (1 << x); }
ll clearBit (ll n, ll x) { return n & ~(1 << x); }
ll toggleBit (ll n, ll x) { return n ^ (1 << x); }
bool getBit (ll n, ll x) { return (bool)(n & (1 << x)); }

const int maxN = 1e6 + 5;
vector<int> primes;
vector<int> pre(maxN + 1, 0);
vector<bool> spf(maxN + 1, true);
void sieve()
{
    // Efficient seive
    int n = maxN;
    spf[0] = spf[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (spf[p])
        {
            for (int i = p * p; i <= n; i += p)
                spf[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (spf[p])
            primes.push_back(p);

    // for(int i=2;i<=n;i++)
    // {
    //     pre[i] = pre[i-1];
    //     if(spf[i])
    //         pre[i]++;
    // }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    map<int, vector<int>> mp;
    vector<int> ans(n, 0);

    rep(i, 0, n)
    {
        int x;
        cin >> x;
        if (mp[x].size() < k)
            mp[x].pb(i);
    }

    // for (auto it : mp)
    // {
    //     cout << it.first << "-> ";
    //     for (auto x : it.second)
    //         cout << x << " ";
    //     cout << endl;
    // }

    int m = 0;
    for (auto e : mp) 
        m += e.second.size();
    m -= m % k;

    int color = 0;
    for (auto &it : mp)
    {
        for (auto &i : it.second)
        {
            ans[i] = ++color;
            color %= k;
            if(--m==0)
                break;
        }
        if(m==0)
            break;
    }

    out(ans);
    // rep(i,0,n)
    //     cout<<ans[i]<<" ";
    // cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // sieve();
    int tests = 1;
    cin >> tests;
    for (int test = 1; test <= tests; test++)
    {
        // cout << "Case #" << test << ": ";
        solve();
    }
    // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}