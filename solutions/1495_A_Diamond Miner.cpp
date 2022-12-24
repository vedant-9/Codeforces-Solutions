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
    vll miners(n),mines(n);
    ll p=0,q=0;
    rep(i,0,2*n)
    {
        ll x,y;
        cin>>x>>y;
        if(x==0)
            miners[p++]=abs(y);
        else
            mines[q++]=abs(x);
    }
    sort(all(miners));
    sort(all(mines));
    // out(miners);
    // out(mines);
    ld ans = 0;
    rep(i,0,n)
    {
        ans += sqrt(pow(miners[i],2)+pow(mines[i],2));
    }
    cout<<spre(15)<<ans<<endl;
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