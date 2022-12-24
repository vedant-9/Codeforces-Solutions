#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define tc int tt; cin>>tt; while(tt--)
#define in(arr, n) for(ll i=0; i<n; i++) cin>>arr[i]
#define out(arr, n) for(ll i=0; i<n; i++) cout<<arr[i]<<" "
#define pb push_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tc
    {
        ll n;
        cin>>n;
        ll A[n];
        in(A,n);

        ll os=0,es=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                es += A[i];
            else
                os += A[i];
        }

        if(es<os)
        {
            for (int i = 0; i < n; i+=2)
            {
                A[i] = 1;
            }
        }
        else
        {
            for (int i = 1; i < n; i+=2)
            {
                A[i] = 1;
            }
            
        }

        for(auto i: A)
            cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}