#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef set<ll> sll;
typedef map<ll,ll> mll;
typedef map<string,ll> msl;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define tc int tt; cin>>tt; while(tt--)
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repr(i,s,e) for(ll i=s;i>=e;i--)
#define in(arr) for(auto &i : arr) cin>>i
#define out(arr) for(auto &i : arr) cout<<i<<" "
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define bs binary_search

void solve()
{
    ll n,d,flag=0,c=0;
    cin>>n>>d;
    ll A[n];
    in(A);
    rep(i,0,n-1)
    {
        rep(j,i+1,n)
        {
            if(A[i]+A[j]<=d)
            {
                flag =1;
                break;
            }
        }
        if(A[i]<=d)
            c++;
    }
    if(flag==1 || (c==n-1 && A[n-1]<=d))
        cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    
}

int main()
{
    fastio;
    tc
    {
        solve();
    }
    return 0;
}