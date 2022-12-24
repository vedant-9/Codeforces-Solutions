// Author - Vedant Valsangkar
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<char> vch;
typedef vector<ll> vll;
typedef vector<string> vst;
typedef set<ll> sll;
typedef map<ll, ll> mll;
typedef map<string, ll> msl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef multiset<ll> msll;

#define int long long
#define rep(i, s, e) for (ll i = s; i < e; i++)
#define repr(i, s, e) for (ll i = s; i >= e; i--)
#define repit(it, A) for (auto it = A.begin(); it != A.end(); it++)
#define mk(A, n, T) T *A = new T[n];
#define in(A)         \
    for (auto &i : A) \
    cin >> i
#define out(A)            \
    for (auto &i : A)     \
        cout << i << " "; \
    cout << endl
#define uniq(A) A.erase(unique(all(A)), A.end())
#define all(A) A.begin(), A.end()
#define allr(A) A.rbegin(), A.rend()
#define pb push_back
#define mp make_pair
#define mem1(A) memset(A, -1, sizeof(A))
#define mem0(A) memset(A, 0, sizeof(A))
#define ppcll __builtin_popcountll
#define M_PI 3.14159265358979323846
#define ff first
#define ss second
#define sz(A) ((ll)(A).size())
#define INF 1e18
#define spre(x) fixed << setprecision(x)
#define endl '\n'

bool per_square(ld a)
{
    if (a < 0)
        return false;
    ll sr = sqrt(a);
    return (sr * sr == a);
}
bool is_prime(ll x)
{
    rep(i, 2, sqrt(x) + 1) if (x % i == 0) return false;
    return true;
}
bool sort_by_sec(const pll &a, const pll &b) { return (a.second < b.second); }

void solve()
{
    ll n;
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    if (sum == 0)
    {
        cout << "NO\n";
        return;
    }
    sort(a, a + n);
    if (sum > 0)
        reverse(a, a + n);
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // sieve();
    int tests = 1;
    cin >> tests;
    for (int test = 1; test <= tests; test++)
    {
        // cout << "Case #" << test << ": ";
        solve();
    }
    // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}