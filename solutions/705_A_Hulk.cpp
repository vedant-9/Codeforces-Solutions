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
    int n;
    cin>>n;
    string l="I love ",h="I hate ";
    repe(i,1,n)
    {
        if(i%2!=0)
            cout<<h;
        else
            cout<<l;
        if(i!=n)
            cout<<"that ";
        else
        {
            cout<<"it";
        }   
    }
}

int main()
{
    fastio;
    solve();
    return 0;
};