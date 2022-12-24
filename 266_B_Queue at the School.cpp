#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
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

void solve()
{
    ll n, t;
    string s;
    cin >> n >> t >> s;
    for (ll i = 0; i < t; i++)
    {
        std::string::size_type n = 0;
        while ((n = s.find("BG", n)) != std::string::npos)
        {
            s.replace(n, 2, "GB");
            n += 2;
        }
    }
    cout << s << endl;
}

int main()
{
    fastio;

    solve();

    return 0;
}