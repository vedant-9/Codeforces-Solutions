#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define tc int tt; cin>>tt; while(tt--)

int main()
{
    tc
    {
        int n, m;
        cin >> n >> m;
        map<int, int> a, b;
        for (int i = 0; i < n; ++i)
        {
            int num; cin >> num;
            a[num] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            int num; cin >> num;
            if (a[num] >= 1)
                ++cnt;
        }
        cout << cnt << endl;
    }
 
}