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

long long int partitioningArray(long long int arr[], long long int n)
{
    long long int ans = 0;

    for (long long int k = 1; k <= n; k++)
    {
        if (n % k == 0)
        {
            long long int i = n / k, g = 0;
            for (long long int j = 0; j < i; j++)
            {
                long long int diff = 0;
                for (long long int l = j; l < n; l += i)
                {
                    diff = __gcd(diff, abs(arr[j] - arr[l]));
                }
                g = __gcd(g, diff);
            }
            ans += (g != 1);
        }
    }

    return ans;
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        inputArray(arr, n);

        long long int ans = 0;

        ans = partitioningArray(arr, n);

        cout << ans << endl;
    }

    return 0;
}