#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define tc int tt; cin>>tt; while(tt--)
#define in(arr, n) for(int i=0; i<n; i++) cin>>arr[i]
#define out(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" "
#define pb push_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string a,b;
    cin>>a>>b;

    for(int i=0;i<a.length();i++)
    {
        a[i] = toupper(a[i]);
    }
    for(int i=0;i<b.length();i++)
    {
        b[i] = toupper(b[i]);
    }

    cout<<a.compare(b)<<endl;

    return 0;
}