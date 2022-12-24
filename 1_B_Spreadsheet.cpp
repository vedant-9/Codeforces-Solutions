// Author - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef long long    ll;
typedef long double  ld;
#define int          long long
#define rep(i,s,e)   for(int i=s;i<e;i++)
#define repr(i,s,e)  for(int i=s;i>=e;i--)
#define in(a)        for(auto &i:a) cin>>i
#define out(a)       for(auto &i:a) cout<<i<<" "; cout<<endl
#define uniq(a)      a.erase(unique(all(a)),a.end())
#define all(a)       a.begin(),a.end()
#define allr(a)      a.rbegin(),a.rend()
#define endl         '\n'

bool per_square(ld x){if(x<0) return 0; ll sr=sqrt(x); return (sr*sr==x);}
bool is_prime(ll x){for(int i=2;i*i<=x;i++) if(x%i==0) return 0; return 1;}

void solve()
{
    string s; cin>>s; int n=s.length();
    int f=0; int i=1; while(i<n and isdigit(s[i])) i++; 
    if(i!=n and i!=1 and s[i]=='C') f=1;
    if(f==0) {
        int i=n-1; while(i>=0 and isdigit(s[i])) i--;
        int row=stoi(s.substr(i+1));
        int col=0,j=i,p=1; while(j>=0) col+=(s[j]-'A'+1)*p,p*=26,j--; 
        cout<<"R"<<row<<"C"<<col<<endl;
    } else {
        int x=i;
        string row=s.substr(1,x-1); 
        int t=stoi(s.substr(x+1)); 
        string col; 
        while(t) {if(t%26==0) col+='Z',t--; else col+=(char)(t%26+'A'-1); t/=26;} 
        reverse(all(col));
        cout<<col<<row<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // sieve();
    int tc = 1;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}