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

bool prime[1000001];
void sieve() 
{ 
    int n = 1000000;
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        }
    }
}
    
void solve()
{
    int d,a,b;
    cin>>d;
    rep(i,1+d,1000000)
    {
        if(prime[i])
        {
            a = i;
            break;
        }
    }
    rep(i,a+d,1000000)
    {
        if(prime[i])
        {
            b = i;
            break;
        }
    }
    cout<<a*b<<endl;
}

int main()
{
    fastio;
    sieve();
    tc
    {
        solve();
    }
    return 0;
}