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
    ll n;
    tc
    {
        cin>>n;
        ll A[n],B[n];
        in(A,n);

        ll i,j=0,k=n-1;
        
        for (ll i = 0; i < n; i++)
        {
            if(i%2==0)
                B[i] = A[j++];
            else
                B[i] = A[k--];
        }
        out(B,n);
        cout<<endl;
    }

    return 0;
}