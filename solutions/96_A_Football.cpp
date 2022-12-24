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

    string s;
    cin>>s;

    if(s.find("0000000")!=std::string::npos || s.find("1111111")!=std::string::npos)
        cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    

    return 0;
}