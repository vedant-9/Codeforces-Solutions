// Author - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long 		      	ll;
typedef long double 	      	ld;
typedef unsigned long long 		ull;
typedef vector<char> 	    	vch;
typedef vector<int> 	      	vi;
typedef vector<ll> 		    	vll;
typedef vector<string> 	  		vst;
typedef set<int> 		      	si;
typedef set<ll> 		        sll;
typedef map<ll,ll> 		    	mll;
typedef map<string,ll> 	  		msl;
typedef pair<ll,ll> 	      	pll;
typedef vector<pll> 	      	vpll;
typedef multiset<ll> 	    	msll;

#define fastio 			    	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int             		long long
#define rep(i,s,e) 		    	for(ll i=s; i<e; i++)
#define repr(i,s,e) 	    	for(ll i=s; i>=e; i--)
#define repit(it,A) 	    	for(auto it = A.begin();it!=A.end();it++)
#define mk(A,n,T) 		    	T *A = new T[n];
#define in(A) 			    	for(auto &i : A) cin>>i
#define out(A) 			    	for(auto &i : A) cout<<i<<" "; cout<<endl
#define uniq(A) 		    	A.erase(unique(all(A)),A.end())
#define all(A) 			    	A.begin(),A.end()
#define allr(A) 			   	A.rbegin(),A.rend()
#define pb 				    	push_back
#define mp 				    	make_pair
#define mem1(A) 		    	memset(A,-1,sizeof(A))
#define mem0(A) 		    	memset(A,0,sizeof(A))
#define ppcll 			    	__builtin_popcountll
#define M_PI 			    	3.14159265358979323846
#define ff 				    	first
#define ss 				    	second
#define sz(A)               	((ll)(A).size())
#define INF 			    	1e18
#define spre(x) 		    	fixed<<setprecision(x)
#define endl 			    	'\n'

bool per_square(ld a) { if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a); }
bool is_prime(ll x) { rep(i,2,sqrt(x)+1) if(x%i == 0) return false; return true; }
bool sort_by_sec(const pll &a, const pll &b) { return (a.second < b.second); } 

void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;

    ll xx=x,yy=y;
    x+=-a+b, y+=-c+d;
    if (x>=x1 && x<=x2 && y>=y1 && y<=y2 && (x2>x1||a+b==0) && (y2>y1||c+d==0))
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}

signed main()
{
    fastio;
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