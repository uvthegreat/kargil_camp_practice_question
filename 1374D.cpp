// accepted

#include <bits/stdc++.h>

using namespace std;
void inputArray(long long int arr[], long long int size)
{
    for (long long int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

long long int zeroRemainderArray(long long int arr[], long long int n, long long int k)
{
    long long int ans = 0;
    // here we use map instead of unorederd map
    // because it unordered map has caused collision in testcase 8
    // due to which program has suffered TLE
    map<long long int, long long int> mp;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % k != 0)
            mp[k - (arr[i] % k)]++;
    }

    long long int maxFreq = -1, maxNum = -1;

    for (auto it : mp)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            maxNum = it.first;
        }
        else if (it.second == maxFreq && it.first > maxNum)
        {
            maxNum = it.first;
        }
    }
    if (maxNum != -1)
    {
        long long int temp = (maxFreq - 1) * k;
        ans = maxNum + temp + 1;
    }

    return ans;
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        long long int arr[n];
        inputArray(arr, n);

        long long int ans = zeroRemainderArray(arr, n, k);

        cout << ans << endl;
    }

    return 0;
}