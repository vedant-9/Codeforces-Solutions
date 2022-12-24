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
        int n;
		cin >> n;
		if (n > 45)
			cout << "-1" << endl;
		else
		{
			vector<int> v;
            int c = 9;
            while(n > 9 || c < n)
            {
                n = n - c;
                v.pb(c);
                c--;
            }
            if(n>0)
                v.pb(n);
            for (int i = v.size() - 1; i >= 0; --i)
				cout << v[i];
			cout << endl;
		}
    }

    return 0;
}