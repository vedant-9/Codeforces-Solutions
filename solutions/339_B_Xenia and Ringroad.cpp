  
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    int loc = 1;
    long long int ans = 0;
    for(int i=0; i<m; i++)
    {
        int now;
        cin>>now;

        if(now >= loc)
            ans += now - loc;
        else
            ans += n - (loc - now);
        loc = now;
    }

    cout << ans << endl;

    return 0;
}