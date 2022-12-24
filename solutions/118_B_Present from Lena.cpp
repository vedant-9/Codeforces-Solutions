#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << " "
                 << " ";
        for (int k = 0; k < i; k++)
            cout << k << " ";
        for (int k = i; k > 0; k--)
            cout << k << " ";
        cout << 0 << "\n";
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n - i; j++)
            cout << " "
                 << " ";
        for (int k = 0; k < i; k++)
            cout << k << " ";
        for (int k = i; k > 0; k--)
            cout << k << " ";
        cout << 0 << "\n";
    }
}
