#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define tc int tt; cin>>tt; while(tt--)
#define in(arr, n) for(ll i=0; i<n; i++) cin>>arr[i]
#define out(arr, n) for(ll i=0; i<n; i++) cout<<arr[i]<<" "
#define pb push_back

using namespace std;

void solve()
{
    string s;
    cin>>s;
    int x = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a' && s[i]<='z')
            x++;
    }
    if(x>=s.length()-x)
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
    else
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper); 
    }
    cout<<s<<endl;
}

int main()
{
    fastio;

    solve();

    return 0;
}