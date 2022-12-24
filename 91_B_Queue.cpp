#include <bits/stdc++.h>
using namespace std;

long long calculateSum(int arr[], int n)
{
    //Write your logic here
    map<int, int> mp;
    int res[n];

    for (int i = n - 1; i >= 0; i--)
    {
        auto it = mp.lower_bound(arr[i]);
        if (it != mp.begin())
        {
            it--;
            res[i] = it->second - i - 1;
        }
        else
        {
            if (mp[arr[i]] == 0)
            {
                mp[arr[i]] = i;
            }
            res[i] = -1;
        }
    }
    
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += res[i];
    }
    for(auto x: res)
        cout<<x<<" ";
    cout<<endl;
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    calculateSum(arr, n);
}
