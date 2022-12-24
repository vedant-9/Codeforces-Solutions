// Author - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long 		      	ll;
typedef long double 	      	ld;
typedef unsigned long long 		ull;
typedef vector<ll> 		    	vll;
typedef vector<string> 	  		vst;
typedef set<ll> 		        sll;
typedef map<ll,ll> 		    	mll;
typedef pair<ll,ll> 	      	pll;
typedef vector<pll> 	      	vpll;
typedef multiset<ll> 	    	msll;

#define int             		long long
#define rep(i,s,e) 		    	for(ll i=s; i<e; i++)
#define repr(i,s,e) 	    	for(ll i=s; i>=e; i--)
#define repit(it,A) 	    	for(auto it = A.begin();it!=A.end();it++)
#define in(A) 			    	for(auto &i : A) cin>>i
#define out(A) 			    	for(auto &i : A) cout<<i<<" "; cout<<endl
#define uniq(A) 		    	A.erase(unique(all(A)),A.end())
#define all(A) 			    	A.begin(),A.end()
#define allr(A) 			   	A.rbegin(),A.rend()
#define pb 				    	push_back
#define mem1(A) 		    	memset(A,-1,sizeof(A))
#define mem0(A) 		    	memset(A,0,sizeof(A))
#define ppcll 			    	__builtin_popcountll
#define M_PI 			    	3.14159265358979323846
#define ff 				    	first
#define ss 				    	second
#define INF 			    	1e18
#define sz(A) 			    	(ll)((A).size())
#define spre(x) 		    	fixed<<setprecision(x)
#define endl 			    	'\n'

bool per_square(ld a) { if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a); }
bool is_prime(ll x) { rep(i,2,sqrt(x)+1) if(x%i == 0) return false; return true; }
bool sort_by_sec(const pll &a, const pll &b) { return (a.second < b.second); } 
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

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

const int maxN = 1e5+1;
vll P;
vll pre(maxN+1,0);
vector<bool> spf(maxN+1,true);
void sieve()
{
    ll n = maxN;
    spf[0] = spf[1] = false;
    for (ll p = 2; p * p <= n; p++)
    {
        if (spf[p])
        {
            for (ll i = p * p; i <= n; i += p)
                spf[i] = false;
        }
    }

    for (ll p = 2; p <= n; p++)
        if (spf[p])
            P.push_back(p);
    
    // for(int i=2;i<=n;i++)
    // {
    //     pre[i] = pre[i-1];
    //     if(spf[i])
    //         pre[i]++;
    // }
}

void solve()
{
    int a,b,k;
    cin>>a>>b>>k;

    if(k==1)
    {
        int g = gcd(a,b);
        if(g==a && g==b)   
            cout<<"NO\n";
        else if(g!=a && g!=b) 
            cout<<"NO\n";
        else
            cout<<"YES\n"; 
        return;
    }

    int c1=0,c2=0;
    for(auto x:P)
    {
        if(x>a)
            break;
        while(a%x==0)
        {
            c1++;
            a /= x;
        }
    }
    if(a>1)
        c1++;

    for(auto x:P)
    {
        if(x>b)
            break;
        while(b%x==0)
        {
            c2++;
            b /= x;
        }
    }
    if(b>1)
        c2++;

    if(c1+c2<k)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int tests = 1;
    cin>>tests;
    for(int test=1;test<=tests;test++)
    {
        // cout << "Case #" << test << ": ";
        solve();
    }
    // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}