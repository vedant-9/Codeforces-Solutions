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
#define out(A) 			for(auto &i : A) cout<<i<<" "; cout<<endl
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

void solve()
{
    ll n;
    cin>>n;
    vpll A(n);
    vll tm(n);
    rep(i,0,n)
    {
        cin>>A[i].ff>>A[i].ss;
    }
    in(tm);
    ll ans=A[0].ff + tm[0];
    rep(i,1,n)
    {
        // calculate departure time and then travel to i+1 in a[i]-b[i-1]+tm[i]
        ans = max(A[i-1].ss,ans+(ll)ceil((A[i-1].ss-A[i-1].ff)*1.0/2)) + (A[i].ff-A[i-1].ss)+tm[i];
    }
    cout<<ans<<endl;
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