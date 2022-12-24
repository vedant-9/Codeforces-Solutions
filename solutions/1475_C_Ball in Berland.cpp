// Credits - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef long double 	ld;
typedef vector<int> 	vi;
typedef vector<ll> 		vll;
typedef vector<string> 	vst;
typedef set<int> 		si;
typedef set<ll> 		sll;
typedef map<ll,ll> 		mll;
typedef map<string,ll> 	msl;
typedef pair<ll,ll> 	pll;
typedef vector<pll> 	vpll;

#define fastio 			ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define tc 				int tt; cin>>tt; while(tt--)
#define rep(i,s,e) 		for(ll i=s; i<e; i++)
#define repr(i,s,e) 	for(ll i=s; i>=e; i--)
#define repit(it,A) 	for(auto it = A.begin();it!=A.end();it++)
#define mk(A,n,T) 		T *A = new T[n];
#define in(A) 			for(auto &i : A) cin>>i
#define out(A) 			for(auto &i : A) cout<<i<<" "
#define uniq(A) 		A.erase(unique(all(A)),A.end())
#define all(A) 			A.begin(),A.end()
#define pb 				push_back
#define mp 				make_pair
#define mem1(A) 		memset(A,-1,sizeof(A))
#define mem0(A) 		memset(A,0,sizeof(A))
#define ppc 			__builtin_popcount
#define ppcll 			__builtin_popcountll
#define M_PI 			3.14159265358979323846
#define ff 				first
#define ss 				second
#define INF 			1e18
#define spre(x) 		fixed<<setprecision(x)

const ll M  = 1e9 + 7;
ll mod(ll x) { return ((x % M + M) % M); }
ll addMod(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll mulMod(ll a, ll b) { return mod(mod(a) * mod(b)); }

ll powMod(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % M;
    ll res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res = mulMod(res, a);
            a = mulMod(a, a);
        b = b / 2;
    }
    return res;
}

ll binpow(ll a, ll b) 
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a*b/(gcd(a,b)); }

ll findGCD(ll A[], ll n)
{
    ll res = A[0];
    rep(i,1,n)
    {
        res = gcd(A[i], res);
        if (res == 1)
            return 1;
    }
    return res;
}

ll setBit (ll n, ll x) { return n | (1 << x); }
ll clearBit (ll n, ll x) { return n & ~(1 << x); }
ll toggleBit (ll n, ll x) { return n ^ (1 << x); }
bool getBit (ll n, ll x) { return (bool)(n & (1 << x)); }

//bool spf[1000001];
//void seive()
//{
//     ll n = 1000000;
//     memset(spf, true, sizeof(spf));
//     spf[0] = spf[1] = false;
//
//     for (ll x = 2; x * x <= n; x++)
//     {
//         if (spf[x]) 
//         {
//             for (int i = x * x; i <= n; i += x)
//                 spf[i] = false;
//         }
//     }
// }

void solve()
{
    ll a,b,k;
    cin>>a>>b>>k;
    ll A[k],B[k];
    in(A);
    in(B);
	mll ma,mb;
	rep(i,0,k)
    {
		ma[A[i]]++;
		mb[B[i]]++;
	}
	ll ans = 0;
	rep(i,0,k)
    {
		ans += (k - 1) - (ma[A[i]] - 1) - (mb[B[i]] - 1);
	}
	cout << ans / 2 << '\n';
}

int main()
{
    fastio;
    tc
    {
        solve();
    }
    // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}