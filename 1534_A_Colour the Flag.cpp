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
template<typename T>bool is_pali(T A){ int n=sz(A); rep(i,0,n/2) { if(A[i]!=A[n-i-1])return 0;} return 1;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

void solve()
{
    int n,m;
    cin>>n>>m;
    vst a(n);
    in(a);

    ll x=-1,y=-1,f=-1;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(a[i][j]=='R')
            {
                x = i,y=j,f=0;
                break;
            }
            if(a[i][j]=='W')
            {
                x = i,y=j,f=1;
                break;
            }
        }
    }

    if((f==0 && (x+y)%2!=0) || (f==1 && (x+y)%2==0))
    {
        // WRWR
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if(a[i][j]!='.')
                {
                    if((i+j)%2==0 && a[i][j]!='W')
                    {
                        cout<<"NO\n";
                        return;
                    }
                    if((i+j)%2!=0 && a[i][j]!='R')
                    {
                        cout<<"NO\n";
                        return;
                    }
                }
            }
        }

        cout<<"YES\n";
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if((i+j)%2==0)
                    cout<<"W";
                else    
                    cout<<"R";
            }
            cout<<endl;
        }
    }
    else
    {
        // RWRW
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if(a[i][j]!='.')
                {
                    if((i+j)%2==0 && a[i][j]!='R')
                    {
                        cout<<"NO\n";
                        return;
                    }
                    if((i+j)%2!=0 && a[i][j]!='W')
                    {
                        cout<<"NO\n";
                        return;
                    }
                }
            }
        }

        cout<<"YES\n";
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if((i+j)%2==0)
                    cout<<"R";
                else    
                    cout<<"W";
            }
            cout<<endl;
        }
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