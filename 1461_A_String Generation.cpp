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
    int n,k;
    tc
    {
        cin>>n>>k;
        string s;
        
        int i;
        for(i=0;i<k-1;i++)
        {
            s += "a";
        }

        for(;i<n;i+=3)
        {
            s += "abc";
        }
        while(i!=n)
        {
            s.erase(i);
            i--;
        }
        s.erase(i);
        cout<<s<<endl;

    }

    return 0;
}