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
    
    int A[5][5];
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>A[i][j];

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(A[i][j]==1)
            {
                cout<<abs(2-i) + abs(2-j)<<endl;
                break;
            }
        }   
    }

    return 0;
}