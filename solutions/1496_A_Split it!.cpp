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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll i = 0, j = n-1,f=0;
    rep(x,0,k)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        {
            f = 1;
            break;
        }
    }
    if(f==1)
    {
        cout<<"NO\n";
        return;
    }
    else
    {
        if(i<=j)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
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