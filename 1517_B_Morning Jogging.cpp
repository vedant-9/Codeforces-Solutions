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

#define fastio 			    	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define tc 				    	int tt; cin>>tt; while(tt--)
#define rep(i,s,e) 		    	for(ll i=s; i<e; i++)
#define repr(i,s,e) 	    	for(ll i=s; i>=e; i--)
#define repit(it,A) 	    	for(auto it = A.begin();it!=A.end();it++)
#define mk(A,n,T) 		    	T *A = new T[n];
#define in(A) 			    	for(auto &i : A) cin>>i
#define out(A) 			    	for(auto &i : A) cout<<i<<" "; cout<<endl
#define uniq(A) 		    	A.erase(unique(all(A)),A.end())
#define all(A) 			    	A.begin(),A.end()
#define pb 				    	push_back
#define mp 				    	make_pair
#define mem1(A) 		    	memset(A,-1,sizeof(A))
#define mem0(A) 		    	memset(A,0,sizeof(A))
#define ppc 			    	__builtin_popcount
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

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vll> A(n,vll(m));

    vector<pair<ll,pll>> B;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cin>>A[i][j];
            ll t = A[i][j];
            B.pb({t,{i,j}});
        }
    }

    sort(all(B));

    ll k = 0;
    ll c = 0;
    
    while(c<m)
    {
        ll val = B[k].ff;
        ll i = B[k].ss.ff;
        ll j = B[k].ss.ss;

        rep(l,0,B.size())
        {
            if(A[i][c]==B[l].ff && i==B[l].ss.ff && c==B[l].ss.ss)
            {
                // ll t = B[l].ff;
                B[l].ss.ss = j;
                B[k].ss.ss = c;
                break;
            }
        }

        swap(A[i][j],A[i][c]);

        k++;

        c++;
    }

    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
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