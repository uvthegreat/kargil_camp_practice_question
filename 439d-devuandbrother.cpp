// accepted
#include <bits/stdc++.h>

using namespace std;

long long int findOptimalOperation(int n, int a[], int m, int b[])
{
    int i = 0;
    long long int ans = 0;
    sort(a, a + n);
    sort(b, b + m, greater<int>());
    while (i < min(n, m))
    {
        if (a[i] < b[i])
        {
            ans += b[i] - a[i];
        }
        i++;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    long long int ans = findOptimalOperation(n, a, m, b);

    cout << ans << endl;

    return 0;
}