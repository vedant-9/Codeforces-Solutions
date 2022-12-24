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

void google(int t) { cout << "Case #" << t << ": "; }
bool per_square(ld a) { if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a); }
bool is_prime(ll x) { rep(i,2,sqrt(x)+1) if(x%i == 0) return false; return true; }
bool sort_by_sec(const pll &a, const pll &b) { return (a.second < b.second); } 

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

void solve(int test)
{
    ll n;
    cin>>n;
    vll A(n);
    in(A);

    ll ind = 0;
    rep(i,1,n)
    {
        if(A[i]<A[ind])
            ind = i;
    }

	cout << n - 1 << endl;
    repr(i,ind-1,0)
    {
		cout << i + 1 << " " << ind + 1 << " ";
		A[i] = A[i + 1] + 1;
		cout << A[i] << " " << A[ind] << endl;
	}

	rep(i,ind+1,n)
    {
		cout << i + 1 << " " << ind + 1  << " ";
		A[i] = A[i - 1] + 1;
		cout << A[i] << " " << A[ind] << endl;
	}
    // out(A);
}

int main()
{
    fastio;
    int tests = 1;
    cin>>tests;
    for(int test=1;test<=tests;test++)
    {
        solve(test);
    }
    // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}