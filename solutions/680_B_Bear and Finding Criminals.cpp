#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef long double 	ld;
typedef vector<int> 	vi;
typedef vector<ll> 		vll;
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
#define pi 				3.141592653589793238
#define ff 				first
#define ss 				second
#define mod 			1000000007
#define inf 			1e18
#define spre(x) 		fixed<<setprecision(x)

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a*b/(gcd(a,b));
}

void solve()
{
    ll n,a,c=0,k=0;
    cin>>n>>a;
    vll A(n);
    in(A);
    c = count(all(A),1);
    // cout<<c<<endl;
    a--;
    while(1)
    {
        if(a-k<0 || a+k>=n)
            break;
        if((A[a-k]==1 && A[a+k]==0) || (A[a-k]==0 && A[a+k]==1))
            c--;
        k++;
    }
    cout<<c<<endl;
}

int main()
{
    fastio;
    // tc
    // {
        solve();
    // }
    return 0;
}