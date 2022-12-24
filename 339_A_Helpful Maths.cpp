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

    char c;
    vector<int> ans;
    int k=0;
    while (cin >> c)
    {
        if (c != '+')
        {
            ans.push_back(c - 48);
        }
        else
        {
            k++;
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (k != 0)
        {
            cout << "+";
            k--;
        }
    }
    return 0;
}