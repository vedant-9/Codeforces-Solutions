#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define tc     \
    int tt;    \
    cin >> tt; \
    while (tt--)
#define in(arr, n)             \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
#define out(arr, n)            \
    for (ll i = 0; i < n; i++) \
    cout << arr[i] << " "
#define pb push_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;

    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}