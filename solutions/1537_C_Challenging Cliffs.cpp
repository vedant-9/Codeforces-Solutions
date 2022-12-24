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
#define out(A) 			    	for(auto &i : A) cout<<i<<" ";
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
template<typename T>bool is_pali(T A){ int n=sz(A); rep(i,0,n/2) { if(A[i]!=A[n-i-1])return 0;} return 1;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

void solve()
{
    int n;
    cin>>n;
    vll a(n);
    in(a);

    sort(all(a));

    int e;
    int md = INT_MAX,e1,e2;
    int f = 0;
    rep(i,1,n)
    {
        if(a[i]==a[i-1])
        {
            e = a[i];
            f=1;
            break;
        }
        if(a[i]-a[i-1]<md)
        {
            e1 = a[i-1];
            e2 = a[i];
            md = a[i]-a[i-1];
        }
    }

    if(f)
    {
        vll small,big;
        int c = 0;
        rep(i,0,n)
        {
            if(c<2 && a[i]==e)
            {
                c++;
                continue;
            }
            if(a[i]<e)
                small.pb(a[i]);
            else
                big.pb(a[i]);
            // cout<<a[i]<<" ";
        }
        cout<<e<<" ";
        out(big);
        out(small);
        cout<<e<<endl;
    }
    else
    {
        vll small,big;
        int f1=0,f2=0;
        rep(i,0,n)
        {
            if(a[i]==e1 && !f1)
            {
                f1=1;
                continue;
            }
            if(a[i]==e2 && !f2)
            {
                f2=1;
                continue;
            }
            if(a[i]<e1)
                small.pb(a[i]);
            else
                big.pb(a[i]);
            // cout<<a[i]<<" ";
        }
        cout<<e1<<" ";
        out(big);
        out(small);
        cout<<e2<<endl;
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // sieve();
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