#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define tc int tt; cin>>tt; while(tt--)
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repe(i,s,e) for(ll i=s;i<=e;i++)
#define repr(i,s,e) for(ll i=s;i>=e;i--)
#define in(arr, n) for(auto &i : arr) cin>>i
#define out(arr, n) for(auto &i : arr) cout<<i<<" "
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define gcd(a,b) __gcd(a,b)
#define setbits(x) __bulitin_popcountll(x)
#define bs binary_search

void solve()
{
    ll n;
    cin>>n;
    if(n==2 || (n/2)%2!=0)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    ll A[n];
    rep(i,0,n)
    {
        if(i<n/2)
        {
            A[i] = 2*(i+1);
        }
        else
        {
            if(i<(3*(n/4)))
                A[i] = A[i-n/2] - 1;
            else
            {
                A[i] = A[i-n/2] + 1;
            }
            
        }
    }
    out(A,n);
    cout<<endl;
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